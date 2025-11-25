# Proyecto C genérico
# Estructura sugerida:
# - src/         código fuente .c
# - include/     headers .h
# - tests/       tests .c (opcional)
# - build/       objetos .o (auto)
# - bin/         ejecutables (auto)

# Nombre del ejecutable principal
TARGET        := app

# Directorios
SRC_DIR       := src
INC_DIR       := include
BUILD_DIR     := build
BIN_DIR       := bin
TEST_DIR      := tests

# Herramientas
CC            := gcc
AR            := ar
RM            := rm -rf
MKDIR_P       := mkdir -p

# Flags comunes
WARN_FLAGS    := -Wall -Wextra -Wpedantic -Wshadow -Wconversion
STD_FLAGS     := -std=c17
OPT_FLAGS     := -O2
DBG_FLAGS     := -g3 -DDEBUG
DEFS          :=
INCLUDES      := -I$(INC_DIR)
LDFLAGS       :=
LDLIBS        :=

# Perfil por defecto: release (cambia a debug con `make debug`)
CFLAGS        := $(STD_FLAGS) $(WARN_FLAGS) $(OPT_FLAGS) $(DEFS) $(INCLUDES)

# Fuentes y objetos
SRC_FILES     := $(shell find $(SRC_DIR) -name '*.c' 2>/dev/null)
OBJ_FILES     := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Binarios
TARGET_BIN    := $(BIN_DIR)/$(TARGET)

# Colores (opcionales)
COLOR_OK      := \033[32m
COLOR_INFO    := \033[36m
COLOR_WARN    := \033[33m
COLOR_ERR     := \033[31m
COLOR_NONE    := \033[0m

.PHONY: all release debug run clean distclean rebuild info test test-run help

all: release

release: CFLAGS := $(STD_FLAGS) $(WARN_FLAGS) -DNDEBUG $(OPT_FLAGS) $(DEFS) $(INCLUDES)
release: LDFLAGS := $(LDFLAGS)
release: $(TARGET_BIN)
	@printf "$(COLOR_OK)[OK]$(COLOR_NONE) Build release: $@\n"

debug: CFLAGS := $(STD_FLAGS) $(WARN_FLAGS) $(DBG_FLAGS) $(DEFS) $(INCLUDES)
debug: LDFLAGS := $(LDFLAGS)
debug: $(TARGET_BIN)
	@printf "$(COLOR_OK)[OK]$(COLOR_NONE) Build debug: $@\n"

# Enlazado final
$(TARGET_BIN): $(OBJ_FILES) | $(BIN_DIR)
	@printf "$(COLOR_INFO)[LD]$(COLOR_NONE) $@\n"
	@$(CC) $(LDFLAGS) -o $@ $(OBJ_FILES) $(LDLIBS)

# Compilación de .c a .o con dependencias automáticas (.d)
# -MMD -MP generan archivos .d para dependencias de headers
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@printf "$(COLOR_INFO)[CC]$(COLOR_NONE) $<\n"
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Directorios
$(BUILD_DIR):
	@$(MKDIR_P) $(BUILD_DIR)

$(BIN_DIR):
	@$(MKDIR_P) $(BIN_DIR)

# Incluir dependencias si existen
# Evita error si aún no se han generado
-include $(OBJ_FILES:.o=.d)

# Ejecutar el binario principal
run: $(TARGET_BIN)
	@printf "$(COLOR_INFO)[RUN]$(COLOR_NONE) $(TARGET_BIN)\n"
	@$(TARGET_BIN)

# Tests simples: compila todos los *.c en tests/ como ejecutables independientes
TEST_SRCS     := $(shell [ -d $(TEST_DIR) ] && find $(TEST_DIR) -maxdepth 1 -name '*.c' 2>/dev/null)
TEST_BINS     := $(patsubst $(TEST_DIR)/%.c,$(BIN_DIR)/test_%,$(TEST_SRCS))
TEST_OBJS     := $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/tests/%.o,$(TEST_SRCS))

test: $(TEST_BINS)
	@printf "$(COLOR_OK)[OK]$(COLOR_NONE) Tests compilados\n"

test-run: test
	@set -e; \
	for t in $(TEST_BINS); do \
		printf "$(COLOR_INFO)[TEST]$(COLOR_NONE) $$t\n"; \
		"$$t"; \
	done

$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	@printf "$(COLOR_INFO)[CC]$(COLOR_NONE) $< (test)\n"
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BIN_DIR)/test_%: $(BUILD_DIR)/tests/%.o $(OBJ_FILES) | $(BIN_DIR)
	@printf "$(COLOR_INFO)[LD]$(COLOR_NONE) $@ (test)\n"
	@$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Limpieza
clean:
	@printf "$(COLOR_WARN)[CLEAN]$(COLOR_NONE) objetos y deps\n"
	@$(RM) $(BUILD_DIR)

distclean: clean
	@printf "$(COLOR_warn)[CLEAN]$(COLOR_NONE) binarios\n"
	@$(RM) $(BIN_DIR)

rebuild: distclean all

# Información útil
info:
	@echo "TARGET      : $(TARGET)"
	@echo "SRC_DIR     : $(SRC_DIR)"
	@echo "INC_DIR     : $(INC_DIR)"
	@echo "BUILD_DIR   : $(BUILD_DIR)"
	@echo "BIN_DIR     : $(BIN_DIR)"
	@echo "CC          : $(CC)"
	@echo "CFLAGS      : $(CFLAGS)"
	@echo "LDFLAGS     : $(LDFLAGS)"
	@echo "LDLIBS      : $(LDLIBS)"
	@echo "Sources     : $(SRC_FILES)"

help:
	@echo "Uso: make [target]"
	@echo "Targets:"
	@echo "  all (por defecto)  -> build release"
	@echo "  release            -> compila con -O2 y NDEBUG"
	@echo "  debug              -> compila con -g y -DDEBUG"
	@echo "  run                -> ejecuta bin/$(TARGET)"
	@echo "  test               -> compila tests/*.c"
	@echo "  test-run           -> ejecuta los tests compilados"
	@echo "  clean              -> elimina build/"
	@echo "  distclean          -> elimina build/ y bin/"
	@echo "  info               -> muestra configuración"
	@echo "  rebuild            -> limpia y recompila"
