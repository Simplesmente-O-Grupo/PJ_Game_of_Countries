src=$(wildcard src/*.c)
obj=$(src:.c=.o)


CC=gcc
CFLAGS=-g -Wall
LINKER_FLAGS=-lcurses

game: $(obj)
	$(CC) -o $@ $(CFLAGS) $(LINKER_FLAGS) $^

clean:
	rm $(obj)
	rm game


