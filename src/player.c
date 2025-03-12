#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "include/player.h"
#include "include/deck.h"

Player playerCreate(int id, char *name, int deck_size) {
	Player player = {
		.id = id
	};
	player.deck = deck_initialize(deck_size);
	assert(player.deck != NULL);
	strcpy(player.name, name);

	return player;
}

void playerDestroy(Player *player) {
	deck_free(player->deck);
}
