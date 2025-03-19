CC=gcc
CFLAGS=-g -Wall -Werror

ifeq ($(OS), WINDOWS_NT)
	LINKER_FLAGS=-Iinclude -Llib -lpdcurses
else
	LINKER_FLAGS=-lcurses
endif

game: main.o ui_utils.o game_setup.o main_menu.o player.o player_list.o deck.o card.o credits.o
	$(CC) -o $@ ${CFLAGS} $^ ${LINKER_FLAGS}

main.o: src/main.c src/include/game_data.h src/include/player_list.h src/include/deck.h src/include/card.h src/include/player.h src/include/game_setup.h src/include/game_data.h src/include/main_menu.h src/include/player_list.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS} 
ui_utils.o: src/ui_utils.c src/include/ui_utils.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS}
game_setup.o: src/screens/game_setup.c src/screens/../include/countries.h src/screens/../include/card.h src/screens/../include/player_list.h src/screens/../include/deck.h src/screens/../include/player.h src/screens/../include/game_data.h src/screens/../include/ui_utils.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS} 
main_menu.o: src/screens/main_menu.c src/screens/../include/game_data.h src/screens/../include/player_list.h src/screens/../include/deck.h src/screens/../include/card.h src/screens/../include/player.h src/screens/../include/ui_utils.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS}
player.o: src/player.c src/include/player.h src/include/deck.h src/include/card.h src/include/deck.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS}
player_list.o: src/player_list.c src/include/player.h src/include/deck.h src/include/card.h src/include/player_list.h src/include/player.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS}
deck.o: src/deck.c src/include/deck.h src/include/card.h src/include/card.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS}
card.o: src/card.c src/include/card.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS}

credits.o: src/screens/credits.c src/screens/../include/game_data.h src/screens/../include/player_list.h src/screens/../include/deck.h src/screens/../include/card.h src/screens/../include/player.h
	$(CC) -c -o $@ ${CFLAGS} $< ${LINKER_FLAGS}
clean:
	rm -v game main.o ui_utils.o game_setup.o main_menu.o player.o player_list.o deck.o card.o credits.o

