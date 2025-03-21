#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static void printTank(int y, int x) {
	mvprintw(y, x, "      '\\                ");
	mvprintw(y+1, x, "       _\\______         ");
	mvprintw(y+2, x, "      /        \\========");
	mvprintw(y+3, x, " ____|__________\\_____  ");
	mvprintw(y+4, x, "/ ___________________ \\ ");
	mvprintw(y+5, x, "\\/ _===============_ \\/ ");
	mvprintw(y+6, x, "  \"-===============-\"   ");
}

static void printHelicopter(int y, int x) {
	mvprintw(y, x, "      (--------v--------)");
	mvprintw(y+1, x, "__        __ __|__       ");
	mvprintw(y+2, x, "(@)______(::(    |@\\_    ");
	mvprintw(y+3, x, " `-------\\___________)   ");
	mvprintw(y+4, x, "         __|___|___,     ");
}

/* Função para mostrar uma tela de carregamento falso.
* Esta função é desnecessária e desperdiça tempo, mas
* deixa o jogo bem mais bonito.
*/
void fakeLoadingScreen(void) {
	srand(time(NULL));
	/* A tela de carregamento escolhe uma destas
	 * frases para mostrar
	 */
	char *loadingMsg[] = {
		"Adquirindo novos estados...",
		"Apagando arquivos...",
		"Na escuridao sombria do terceiro milenio, so ha guerra.",
		"Sabotando linhas logísticas..."
	};
	int messages = sizeof(loadingMsg) / sizeof(loadingMsg[0]);
	int chosenMsg = rand() % messages;
	timeout(50);

	int heliY = (LINES/3);
	int heliX = rand() % 10;
	for (int i = 0; i < COLS-24; i++) {
		/* Move o helicóptero para baixo em um
		* intervalo de espaços
		*/
		if (i % 7 == 0) heliY++;
		else if (i % 7 == 6) heliY--;
		/****************************/

		clear();
		mvprintw(LINES/2, (COLS - strlen(loadingMsg[chosenMsg])) / 2, "%s", loadingMsg[chosenMsg]);
		printTank(2 * LINES / 3, i);
		printHelicopter(heliY, heliX + i);
		refresh();
		getch();
	}
	timeout(-1);
}
