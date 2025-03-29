#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "include/player.h"
#include "include/deck.h"
#include "include/countries.h"

/*
► Função para criar um jogador:
► Recebendo como parâmetro um inteiro e uma constante do tipo char.
► A função inicializa com um id e um deck.

*/
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

/*
► Função para transferência de cartas.
► Parâmetro que recebe um jogador para receber a carta e outro para perder.
► deckPop remove a carta do jogador perdedor e insere no ganhador.
*/
void playerTransferCard(Player *dest, Player *src)
{
	deckPush(dest->deck, deckPop(src->deck));
}

/*
► Liberar a memória do deck do jogador.
► Verifica se é um jogador e um deck válido.
► Libera a memória do deck do jogador.
► Definindo como NULL para evitar o uso acidental.
*/
void playerDestroy(Player *player)
{
	if (player != NULL)
	{
		if (player->deck != NULL)
		{
			deckFree(player->deck);
			player->deck = NULL;
		}
	}
}
