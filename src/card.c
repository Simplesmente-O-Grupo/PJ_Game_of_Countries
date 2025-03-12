#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/card.h"

// FUNCTIONS IMPLEMENTATIONS

/*
 * Cria uma carta. Só é usada no início do jogo para popular
 * o deck principal.
*/
Card create_card(int id, char *name, char *category, int defence, int army, int navy, int airforce) {
	Card card = {
		.id = id,
		.defence = defence,
		.army = army,
		.navy = navy,
		.airforce = airforce
	};

	strcpy(card.name, name);
	strcpy(card.category, category);

	return card;
}
