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
	
	/* Etapa 1: Obter a quantidade de usuários */
	IntField playerQuantityField;
	createIntField(&playerQuantityField, menuWidth, (LINES - 3)/2, (COLS - menuWidth)/2, "Quantidade de jogadores", 4, 2);
	focusIntField(&playerQuantityField);

	erase();
	refresh();

	/*******************************************/

	/* Etapa 2: Obter nomes de usuário*/
	StrField playerNameField;
	createStrField(&playerNameField, menuWidth, (LINES - 3)/2,(COLS - menuWidth)/2, "Nome do jogador");

	for (int i = 0; i < playerQuantityField.value; i++)
	{
		mvprintw((LINES - 3)/2 + 3, (COLS - menuWidth)/2 + 1, "Jogador %d/%d", i + 1, playerQuantityField.value);
		refresh();
		do {
			focusStrField(&playerNameField);
		} while(!playerListNameIsUnique(game->players, playerNameField.value));
		playerListInsert(&game->players, playerCreate(i, playerNameField.value));
		playerNameField.value[0] = '\0';
	}
	/* Estes campos não são mais necessário */
	delwin(playerQuantityField.window);
	delwin(playerNameField.window);
	/*******************************************/

	/* Etapa 3: Distribuir as cartas */
	Card *cartas;
	initializeCountryList(&cartas);
	shuffle(cartas, GLOBAL_COUNTRIES_AMOUNT);
	distributeCards(cartas, game->players);

	game->maxCards = (GLOBAL_COUNTRIES_AMOUNT / playerQuantityField.value) * (playerQuantityField.value);
	freeCountryList(&cartas);
	/*******************************************/

	game->state = IN_GAME;
	fakeLoadingScreen();
}
