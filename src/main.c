#include <stdio.h>
#include <curses.h>

#include "include/game_data.h"
#include "include/game_setup.h"
#include "include/main_menu.h"
#include "include/player_list.h"
#include "include/credits.h"
#include "include/game_screen.h"

int main() {
	initscr(); /* Inicializa a biblioteca curses */
	noecho();  /* Não exibe os caracteres digitados pelo usuário */
	curs_set(0); /* Esconde o cursor do terminal */
	keypad(stdscr, TRUE); /* Habilita teclas de funções, como as setas do teclado */

	GameData game = {
		.state = MAIN_MENU,
		.players = NULL
	};

	/* Ciclo do jogo, o estado define a tela para mostrar */
	while (game.state != EXIT) {
		/* Apaga conteúdo da tela */
		clear();
		/* Atualiza o conteúdo da tela */
		switch(game.state) {
			case MAIN_MENU:
				mainMenuScreen(&game);
				break;
			case GAME_SETUP:
				gameSetupScreen(&game);
				break;
			case IN_GAME:
				gameScreen(&game);
				break;
			case CREDITS_SCREEN:
				creditsScreen(&game);
				break;
			case EXIT:
				playerListFree(&game.players);
				break;
		}
	}

	endwin(); /* Libera memória alocada pelo curses. */
	return 0;
}



