CC=gcc
CFLAGS=-g -Wall -Werror

ifeq ($(OS), WINDOWS_NT)
	LINKER_FLAGS=-Iinclude -Llib -lpdcurses
else
	LINKER_FLAGS=-lcurses
endif

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TARGET = $(BIN_DIR)/game

$(TARGET):$(OBJ_FILES)
	$(CC) ${CFLAGS} $^ ${LINKER_FLAGS} -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ ${LINKER_FLAGS}

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/* $(TARGET)
