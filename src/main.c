#include <stdio.h>
#include <curses.h>

int main() {
	initscr();
	mvprintw(LINES/2, (COLS + 6)/2, "Hello, World!");
	refresh();
	getch();
	endwin();
	return 0;
}
