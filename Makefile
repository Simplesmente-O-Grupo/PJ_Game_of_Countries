CC=gcc
CFLAGS=-g -Wall -Werror
LINKER_FLAGS=-lcurses

game: main.o ui_utils.o main_menu.o 
	$(CC) -o $@ $(CFLAGS) $^ $(LINKER_FLAGS) 

main.o: src/main.c src/include/game_state.h src/include/main_menu.h src/include/ui_utils.h
	$(CC) -c -o $@ $(CFLAGS) $< $(LINKER_FLAGS) 

ui_utils.o: src/ui_utils.c
	$(CC) -c -o $@ $(CFLAGS) $< $(LINKER_FLAGS) 

main_menu.o: src/screens/main_menu.c src/include/game_state.h src/include/ui_utils.h
	$(CC) -c -o $@ $(CFLAGS) $< $(LINKER_FLAGS) 

clean:
	rm -v main.o ui_utils.o main_menu.o game

