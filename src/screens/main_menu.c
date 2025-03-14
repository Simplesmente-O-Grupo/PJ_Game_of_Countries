#include <curses.h>

#include "../include/game_state.h"
#include "../include/ui_utils.h"

#define LOGO_WIDTH 48
#define LOGO_HEIGHT 4

void printLogo(int y, int x) {
	mvprintw(y,   x, "  ____              _  __        __             ");
	mvprintw(y+1, x, " / ___|__ _ _ __ __| | \\ \\      / /_ _ _ __ ___ ");
	mvprintw(y+2, x, "| |   / _` | '__/ _` |  \\ \\ /\\ / / _` | '__/ __|");
	mvprintw(y+3, x, "| |__| (_| | | | (_| |   \\ V  V / (_| | |  \\__ \\");
	mvprintw(y+4, x, " \\____\\__,_|_|  \\__,_|    \\_/\\_/ \\__,_|_|  |___/");
}

void mainMenuScreen(GameState *state) {
	/* Opções definidas no requisito RFGUI02 */
	char *options[] = {
		"Novo jogo",
		"Creditos ",
		"Sair     "
	};

	/* Número de opções do menu principal */
	int numOptions = sizeof(options) / sizeof(options[0]);
	/* Índice da opção selecionada, por padrão é a primeira */
	int option = 0;
	int key;
	int exit_screen = 0;

	/* Cria uma janela no centro da tela com o tamanho necessário
	 * para os botões do menu principal
	 */
	WINDOW *menu = newwin(numOptions + 2, 12, LINES/2 - ((numOptions + 2) / 2), (COLS/2) - 12/2);

	/* A função getch interrompe a execução do programa.
	 * Por isso, é necessário imprimir a tela uma vez antes
	 * de entrar no loop.
	 *
	 * Se eu não fizer isto, a tela ficará limpa até o
	 * usuário pressionar alguma tecla.
	 */
	printLogo((LINES/2) - LOGO_HEIGHT *  2, (COLS/2) - (LOGO_WIDTH / 2));
	wprintListMenu(menu, options, numOptions, option);
	refresh();
	wrefresh(menu);
	/*********************************************************/

	do {
		/* coleta entrada do usuário */
		key = getch();
		switch(key) {
			case 'k':
				option = (numOptions - 1 + option) % numOptions;
				break;
			case 'j':
				option = (option + 1) % numOptions;
				break;
			case '\n': /* Enter/Return */
				exit_screen = 1;
				if (option == 2) {
					/* O estado EXIT informa o programa para
					 * encerrar execução
					 */
					*state = EXIT;
				}
		}

		printLogo((LINES/2) - LOGO_HEIGHT *  2, (COLS/2) - (LOGO_WIDTH / 2));
		wprintListMenu(menu, options, numOptions, option);
		/* imprime os conteúdos da tela padrão */
		refresh();
		/* imprime os conteúdos da janela de menu */
		wrefresh(menu);

	} while (!exit_screen);

	/* Libera memória alocada pela janela de menu */
	delwin(menu);
}
