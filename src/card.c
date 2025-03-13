#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/card.h"

// FUNCTIONS IMPLEMENTATIONS

Card createCard(int id, char *name, char *category, int defence, int army, int navy, int airforce) {
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
