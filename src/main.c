#include <stdio.h>
#include <curses.h>

#include "include/game_state.h"
#include "include/main_menu.h"

int main() {
	initscr(); /* Inicializa a biblioteca curses */
	noecho();
	curs_set(0); /* Esconde o cursor do terminal */

	GameState state = MAIN_MENU;

	/* Ciclo do jogo, o estado define a tela para mostrar */
	while (state != EXIT) {
		/* Apaga conteúdo da tela */
		clear();
		switch(state) {
			case MAIN_MENU:
				mainMenuScreen(&state);
				break;
			case GAME_SETUP:
				break;
			case IN_GAME:
				/* Lógica de jogo aqui */
				break;
			case CREDITS_SCREEN:
				/* Lógica de créditos aqui */
				break;
			case EXIT:
				break;
		}
	}

	endwin(); /* Libera memória alocada pelo curses. */
	return 0;
}



