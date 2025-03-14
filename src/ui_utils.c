#include <curses.h>

void mvprintbutton(int y, int x, char *label, int selected) {
	if (selected)
		/* Ativa destaque de texto */
		attron(A_STANDOUT);
	mvprintw(y, x, "%s", label);
	/* Desativa destaque de texto */
	attroff(A_STANDOUT);
}
void mvwprintbutton(WINDOW *window, int y, int x, char *label, int selected) {
	if (selected)
		wattron(window, A_STANDOUT);
	mvwprintw(window, y, x, "%s", label);
	wattroff(window, A_STANDOUT);
}

void wprintListMenu(WINDOW * window, char *options[], int numOptions, int currOption) {
	int selected = 0;
	/* desenha uma borda padrão para a janela */
	box(window, 0, 0);
	for (int i = 0; i < numOptions; i++) {
		if (currOption == i)
			selected = 1;
		else
			selected = 0;
		mvwprintbutton(window, i+1, 1, options[i], selected);
	}
}
