#include <curses.h>

#include "../include/game_data.h"
#include "../include/ui_utils.h"

#define LOGO_WIDTH 48
#define LOGO_HEIGHT 4

static void printLogo(int y, int x) {
	mvprintw(y,   x, "  ____              _  __        __             ");
	mvprintw(y+1, x, " / ___|__ _ _ __ __| | \\ \\      / /_ _ _ __ ___ ");
	mvprintw(y+2, x, "| |   / _` | '__/ _` |  \\ \\ /\\ / / _` | '__/ __|");
	mvprintw(y+3, x, "| |__| (_| | | | (_| |   \\ V  V / (_| | |  \\__ \\");
	mvprintw(y+4, x, " \\____\\__,_|_|  \\__,_|    \\_/\\_/ \\__,_|_|  |___/");
}

static void printHelicopter(int y, int x) {
	mvprintw(y, x, "--------------------------------------");
	mvprintw(y+1, x, "                  ||                  ");
	mvprintw(y+2, x, "               --/__\\--               ");
	mvprintw(y+3, x, "              |o/    \\o|              ");
	mvprintw(y+4, x, "               -|----|-               ");
	mvprintw(y+5, x, "          o-----|    |-----o          ");
	mvprintw(y+6, x, "            O O  ----  O O            ");
	mvprintw(y+7, x, "                /    \\                ");
}
static void printTank(int y, int x, int invert) {
	if (!invert) {
		mvprintw(y, x, "   [ O ]");
		mvprintw(y+1, x, "     \\ \\     ");
		mvprintw(y+2, x, "      \\ \\  ");
		mvprintw(y+3, x, "       \\ \\-------_");
		mvprintw(y+4, x, "       /\\ \\   / ~~\\_");
		mvprintw(y+5, x, " ./---/__|=/_/------//~~~\\");
		mvprintw(y+6, x, "/___________________/O   O \\");
		mvprintw(y+7, x, "(===(\\_________(===(Oo o o O)         ");
		mvprintw(y+8, x, " \\~~~\\____/     \\---\\Oo__o--");
		mvprintw(y+9, x, "   ~~~~~~~       ~~~~~~~~~~");
	} else {
		mvprintw(y, x, "                     [ O ]   ");
		mvprintw(y+1, x, "                     / /     ");
		mvprintw(y+2, x, "                    / /      ");
		mvprintw(y+3, x, "           _-------/ /       ");
		mvprintw(y+4, x, "         _/~~ \\   / /\\       ");
		mvprintw(y+5, x, "   /~~~\\\\------\\_\\=|__\\---\\. ");
		mvprintw(y+6, x, " / O   O\\___________________\\");
		mvprintw(y+7, x, "(O o o oO)===)_________/)===)");
		mvprintw(y+8, x, "  --o__oO/---/     \\____/~~~/");
		mvprintw(y+9, x, "   ~~~~~~~~~~       ~~~~~~~  ");
	}
}
void mainMenuScreen(GameData *game) {
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

	int menuWidth = 12;
	int menuHeight = numOptions+2;

	/* Cria uma janela no centro da tela com o tamanho necessário
	 * para os botões do menu principal
	 */
	WINDOW *menu = newwin(menuHeight, menuWidth, LINES/2 - ((numOptions + 2) / 2), (COLS/2) - 12/2);

	/* A função getch interrompe a execução do programa.
	 * Por isso, é necessário imprimir a tela uma vez antes
	 * de entrar no loop.
	 *
	 * Se eu não fizer isto, a tela ficará limpa até o
	 * usuário pressionar alguma tecla.
	 */

	clear();
	printHelicopter(3, (COLS - 38) / 2);
	printLogo((LINES/2) - LOGO_HEIGHT *  2, (COLS/2) - (LOGO_WIDTH / 2));
	printTank((LINES) / 2, (COLS) / 2 + menuWidth, 0);
	printTank((LINES) / 2, (COLS) / 2 - (menuWidth + 29), 1);

	wprintListMenu(menu, options, numOptions, option);
	refresh();
	wrefresh(menu);
	/*********************************************************/

	do {
		/* coleta entrada do usuário */
		key = getch();
		switch(key) {
			case KEY_UP:
				option = (numOptions - 1 + option) % numOptions;
				break;
			case KEY_DOWN:
				option = (option + 1) % numOptions;
				break;
			case '\n': /* Enter/Return */
				exit_screen = 1;
				if (option == 2) {
					/* O estado EXIT informa o programa para
					 * encerrar execução
					 */
					game->state = EXIT;
				} else if (option == 0) {
					game->state = GAME_SETUP;
				} else if (option == 1) {
					game->state = CREDITS_SCREEN;
				}
		}

		clear();
		printHelicopter(3, (COLS - 38) / 2);
		printLogo((LINES/2) - LOGO_HEIGHT *  2, (COLS/2) - (LOGO_WIDTH / 2));
		printTank((LINES) / 2, (COLS) / 2 + menuWidth, 0);
		printTank((LINES) / 2, (COLS) / 2 - (menuWidth + 29), 1);
		wprintListMenu(menu, options, numOptions, option);
		/* imprime os conteúdos da tela padrão */
		refresh();
		/* imprime os conteúdos da janela de menu */
		wrefresh(menu);

	} while (!exit_screen);

	/* Libera memória alocada pela janela de menu */
	delwin(menu);
}
