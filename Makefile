CC=gcc
CFLAGS=-g -Wall -Werror

LINKER_FLAGS=-Iinclude -Llib -lpdcurses

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TARGET = game

$(TARGET):$(OBJ_FILES)
	$(CC) ${CFLAGS} $^ ${LINKER_FLAGS} -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ ${LINKER_FLAGS}

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/* $(TARGET)
