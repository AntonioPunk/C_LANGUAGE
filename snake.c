#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <ncurses.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_TAIL (WIDTH * HEIGHT - 1)
#define INITIAL_DELAY_US 100000
#define MIN_DELAY_US 30000
#define DELAY_STEP_US 2500

int x, y, fruitX, fruitY, score;
int tailX[MAX_TAIL], tailY[MAX_TAIL];
int nTail;
int gameOver;
int frameDelayUs;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

void SleepMicroseconds(int microseconds);
void UpdateTail();
void MoveHead();
void WrapPosition();
int CheckSelfCollision();
void HandleFruitConsumption();

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

void PlaceFruit() {
    if (nTail + 1 >= WIDTH * HEIGHT) {
        return;
    }

    do {
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    } while (IsCellOccupied(fruitX, fruitY));
}

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
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printw("o");
                        print = 1;
                        break;
                    }
                }
                if (!print)
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

void WrapPosition() {
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;
}

int CheckSelfCollision() {
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            return 1;
        }
    }

    return 0;
}

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

void SleepMicroseconds(int microseconds) {
    if (microseconds <= 0) {
        return;
    }

    struct timespec remaining;
    remaining.tv_sec = microseconds / 1000000;
    remaining.tv_nsec = (microseconds % 1000000) * 1000;

    while (nanosleep(&remaining, &remaining) == -1 && errno == EINTR) {
        /* Reintenta con el tiempo restante si una señal interrumpe el sueño. */
    }
}
