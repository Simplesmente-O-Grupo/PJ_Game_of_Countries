#include <curses.h>

#include "../include/countries.h"
#include "../include/game_data.h"
#include "../include/ui_utils.h"
#include "../include/fake_loading.h"

void gameSetupScreen(GameData *game)
{
	playerListFree(&game->players);
	erase();
	refresh();
	int menuWidth = 40;
	int menuHeight = 3;
	
	/* Etapa 1: Obter a quantidade de usuários */
	IntField playerQuantityField;
	createIntField(&playerQuantityField, menuHeight, menuWidth, (LINES - menuHeight)/2, (COLS - menuWidth)/2, "Quantidade de jogadores", 4);
	focusIntField(&playerQuantityField);

	erase();
	refresh();

	/*******************************************/

	/* Etapa 2: Obter nomes de usuário*/
	StrField playerNameField;
	createStrField(&playerNameField, menuHeight, menuWidth, (LINES - menuHeight)/2,(COLS - menuWidth)/2, "Nome do jogador");

	for (int i = 0; i < playerQuantityField.value; i++)
	{
		mvprintw((LINES - menuHeight)/2 + 3, (COLS - menuWidth)/2 + 1, "Jogador %d/%d", i + 1, playerQuantityField.value);
		refresh();
		focusStrField(&playerNameField);
		playerListInsert(&game->players, playerCreate(i, playerNameField.value));
		playerNameField.value[0] = '\0';
	}
	/* Estes campos não são mais necessário */
	delwin(playerQuantityField.window);
	delwin(playerNameField.window);
	/*******************************************/

	game->state = MAIN_MENU;
	fakeLoadingScreen();
}
