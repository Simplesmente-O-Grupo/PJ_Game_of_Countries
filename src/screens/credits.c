#include <curses.h>
#include <string.h>
#include "../include/game_data.h"

static void printCredits(char *lines[], int linesAmount, int y);
void creditsScreen(GameData *game)
{
	char *lines[] = {
		"  ____              _  __        __             ",
		" / ___|__ _ _ __ __| | \\ \\      / /_ _ _ __ ___ ",
		"| |   / _` | '__/ _` |  \\ \\ /\\ / / _` | '__/ __|",
		"| |__| (_| | | | (_| |   \\ V  V / (_| | |  \\__ \\",
		" \\____\\__,_|_|  \\__,_|    \\_/\\_/ \\__,_|_|  |___/",
		"-------------",
		"",
		"Planejamento",
		"------------",
		"Luiz Gustavo Monteiro dos Reis",
		"",
		"Matheus Ferreira Guedes",
		"",
		"Gustavo Eklund Franca",
		"",
		"Bruno Romero Morales",
		"",
		"Pedro Juliani Goncalves",
		"",
		"Nathalia Veiga",
		"",
		"Programacao",
		"-----------",
		"Matheus Ferreira Guedes",
		"",
		"Luiz Gustavo Monteiro dos Reis",
		"",
		"Documentacao",
		"------------",
		"Luiz Gustavo Monteiro dos Reis",
		"",
		"Gustavo Eklund Franca",
		"",
		"Nathalia Veiga",
		"",
		"Bruno Romero Morales",
		"",
		"Matheus Ferreira Guedes",
		"",
		"Pedro Juliani Goncalves"

	};
	int y = LINES;
	int linesAmount = sizeof(lines) / sizeof(lines[0]);

	timeout(850);
	while(getch() != 'q')
	{
		erase();
		printCredits(lines, linesAmount, y);
		mvprintw(0, 0, "Pressione 'q' para sair.");
		refresh();

		y--;
		if (y < 0 - linesAmount) y = LINES;
	}

	game->state = MAIN_MENU;
	timeout(-1);
}

static void printCredits(char *lines[], int linesAmount, int y)
{
	for(int i = 0; i < linesAmount; i++)
	{
		int lineLen = strlen(lines[i]);
		mvprintw(y + i, (COLS - lineLen)/2, "%s", lines[i]);
	}
}
