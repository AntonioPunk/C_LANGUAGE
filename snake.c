/*
 * Simple Snake game implemented using ncurses.
 * The game logic maintains the snake head, tail, fruit position, and score.
 * The snake wraps around the board edges and grows when it eats fruit.
 */

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <ncurses.h>

/* Game board dimensions and timing constants. */
#define WIDTH 20
#define HEIGHT 20
#define MAX_TAIL (WIDTH * HEIGHT - 1)
#define INITIAL_DELAY_US 100000
#define MIN_DELAY_US 30000
#define DELAY_STEP_US 2500

/* Global gameplay state. */
int x, y;                    /* Snake head position. */
int fruitX, fruitY;          /* Fruit position on the board. */
int score;                   /* Player score. */
int tailX[MAX_TAIL];         /* Tail segment x-coordinates. */
int tailY[MAX_TAIL];         /* Tail segment y-coordinates. */
int nTail;                   /* Current length of the tail. */
int gameOver;                /* Game-over flag. */
int frameDelayUs;            /* Delay between frames in microseconds. */

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;         /* Current snake direction. */

/* Forward declarations for helper functions. */
void SleepMicroseconds(int microseconds);
void UpdateTail();
void MoveHead();
void WrapPosition();
int CheckSelfCollision();
void HandleFruitConsumption();

/*
 * Returns 1 if the specified cell is occupied by the snake head or any tail segment.
 */
int IsCellOccupied(int cellX, int cellY) {
    if (x == cellX && y == cellY) {
        return 1;
    }

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == cellX && tailY[i] == cellY) {
            return 1;
        }
    }

    return 0;
}

/*
 * Randomly places the fruit on an unoccupied board cell.
 * If the board is full, the function returns without placing a new fruit.
 */
void PlaceFruit() {
    if (nTail + 1 >= WIDTH * HEIGHT) {
        return;
    }

    do {
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    } while (IsCellOccupied(fruitX, fruitY));
}

/*
 * Initializes ncurses and game state variables before the game loop starts.
 */
void Setup() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);

    dir = STOP;
    gameOver = 0;
    frameDelayUs = INITIAL_DELAY_US;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    nTail = 0;
    score = 0;

    srand((unsigned int)time(NULL));
    PlaceFruit();
}

/*
 * Draws the current game board, including borders, snake, fruit, and score.
 */
void Draw() {
    clear();

    for (int i = 0; i < WIDTH + 2; i++)
        printw("#");
    printw("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printw("#");

            if (i == y && j == x)
                printw("O");
            else if (i == fruitY && j == fruitX)
                printw("F");
            else {
                int printed = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printw("o");
                        printed = 1;
                        break;
                    }
                }
                if (!printed)
                    printw(" ");
            }

            if (j == WIDTH - 1)
                printw("#");
        }
        printw("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printw("#");
    printw("\n");
    printw("Score: %d\n", score);
    printw("Flechas para mover, 'x' para salir.\n");

    refresh();
}

/*
 * Reads user input and updates the snake direction or game-over flag.
 * Prevents reversing direction directly into the snake body.
 */
void Input() {
    int ch = getch();
    if (ch != ERR) {
        switch (ch) {
        case KEY_LEFT:
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case KEY_RIGHT:
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case KEY_UP:
            if (dir != DOWN)
                dir = UP;
            break;
        case KEY_DOWN:
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
        case 'X':
            gameOver = 1;
            break;
        }
    }
}

/*
 * Shifts the tail segments so the first segment follows the head, and each
 * subsequent segment follows the one in front of it.
 */
void UpdateTail() {
    if (nTail <= 0) {
        return;
    }

    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        int currentX = tailX[i];
        int currentY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = currentX;
        prevY = currentY;
    }
}

/*
 * Moves the snake head one cell in the current direction.
 */
void MoveHead() {
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
}

/*
 * Wraps the snake around the board edges so it appears on the opposite side.
 */
void WrapPosition() {
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;
}

/*
 * Checks whether the snake head collided with any tail segment.
 */
int CheckSelfCollision() {
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            return 1;
        }
    }

    return 0;
}

/*
 * Handles fruit collection: increases score, grows the snake, accelerates the game,
 * and places a new fruit. Ends the game if the board is full.
 */
void HandleFruitConsumption() {
    if (x == fruitX && y == fruitY) {
        score += 10;
        if (nTail < MAX_TAIL) {
            nTail++;
        }

        if (frameDelayUs > MIN_DELAY_US) {
            frameDelayUs -= DELAY_STEP_US;
            if (frameDelayUs < MIN_DELAY_US) {
                frameDelayUs = MIN_DELAY_US;
            }
        }

        if (nTail + 1 >= WIDTH * HEIGHT) {
            gameOver = 1;
            return;
        }

        PlaceFruit();
    }
}

/*
 * Executes a single game tick: update tail, move the head, wrap position,
 * detect self-collision, and process fruit consumption.
 */
void Logic() {
    UpdateTail();
    MoveHead();
    WrapPosition();

    if (CheckSelfCollision()) {
        gameOver = 1;
        return;
    }

    HandleFruitConsumption();
}

/*
 * Main entry point. Initializes the game, runs the game loop, then cleans up ncurses.
 */
int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        SleepMicroseconds(frameDelayUs);
    }

    nodelay(stdscr, FALSE);
    mvprintw(HEIGHT + 4, 0, "Fin del juego. Puntaje final: %d", score);
    mvprintw(HEIGHT + 5, 0, "Presiona cualquier tecla para salir...");
    refresh();
    getch();
    endwin();
    return 0;
}

/*
 * Sleeps for the requested number of microseconds, retrying if nanosleep is
 * interrupted by a signal.
 */
void SleepMicroseconds(int microseconds) {
    if (microseconds <= 0) {
        return;
    }

    struct timespec remaining;
    remaining.tv_sec = microseconds / 1000000;
    remaining.tv_nsec = (microseconds % 1000000) * 1000;

    while (nanosleep(&remaining, &remaining) == -1 && errno == EINTR) {
        /* Retry with the remaining sleep time if interrupted. */
    }
}
