#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "include/player.h"
#include "include/deck.h"
#include "include/countries.h"

Player playerCreate(int id, const char *name)
{
	Player player = {
		.id = id,
		.deck = NULL // Inicializa o deck como NULL
	};

	// Copia o nome para a estrutura
	strncpy(player.name, name, PLAYER_NAME_MAXLEN - 1);
	player.name[PLAYER_NAME_MAXLEN - 1] = '\0'; // Garante que a string seja terminada corretamente

	// Inicializa o baralho do jogador
	player.deck = deckInitialize(GLOBAL_COUNTRIES_AMOUNT);
	if (player.deck == NULL)
	{
		fprintf(stderr, "[ERR]: Falha ao criar o baralho do jogador.\n");
	}

	return player;
}


void playerTransferCard(Player *dest, Player *src) {
	deckPush(dest->deck, deckPop(src->deck));
}

void playerDestroy(Player *player)
{
	if (player != NULL)
	{
		if (player->deck != NULL)
		{
			deckFree(player->deck); // Libera o baralho do jogador
			player->deck = NULL;	// Define o ponteiro como NULL para evitar uso acidental
		}
	}
}
