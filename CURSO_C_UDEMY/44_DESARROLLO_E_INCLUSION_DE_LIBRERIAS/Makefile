# ============================
#      MAKEFILE MEJORADO
# ============================

# Compilador y opciones
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -Iinclude -MMD -MP
LDFLAGS := 

# Directorios
SRC_DIR := src
BUILD_DIR := build

# Buscar todos los .c dentro de src/
SOURCES := $(wildcard $(SRC_DIR)/*.c)

# Convertir src/archivo.c -> build/archivo.o
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# Archivos de dependencias generados automáticamente
DEPS := $(OBJECTS:.o=.d)

# Nombre del ejecutable
TARGET := ejecutable.exe

# ============================
#     REGLA PRINCIPAL
# ============================

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "🔗 Linkeando $@..."
	@$(CC) -o $@ $^ $(LDFLAGS)

# ============================
#   COMPILACIÓN DE .c → .o
# ============================

# build/archivo.o depende de src/archivo.c
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "📦 Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Crear directorio build/ si no existe
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# ============================
#      REGLAS AUXILIARES
# ============================

clean:
	@echo "🧹 Limpiando archivos..."
	@rm -rf $(BUILD_DIR) $(TARGET)

run: all
	@echo "🚀 Ejecutando programa:"
	./$(TARGET)

info:
	@echo "Fuentes:  $(SOURCES)"
	@echo "Objetos:  $(OBJECTS)"
	@echo "Target:   $(TARGET)"

# ============================
#   INCLUIR DEPENDENCIAS .d
# ============================

-include $(DEPS)

# ============================
#     EVITAR CONFLICTOS
# ============================

.PHONY: all clean run info
