#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/card.h"

// FUNCTIONS IMPLEMENTATIONS

Card createCard(int id, char *name, char *category, int defence, int army, int navy, int airforce)
{
	Card card = {
		.id = id,
		.defence = defence,
		.army = army,
		.navy = navy,
		.airforce = airforce};

	strcpy(card.name, name);
	strcpy(card.category, category);

	return card;
}

// Pega o atributo da carta e retornar o seu valor
int cardGetAttribute(Card card, CardAttribute attr)
{
	int attrValue;
	switch (attr)
	{
	case AIRFORCE:
		attrValue = card.airforce;
		break;
	case NAVY:
		attrValue = card.navy;
		break;
	case DEFENCE:
		attrValue = card.defence;
		break;
	case ARMY:
		attrValue = card.army;
		break;
	default:
		attrValue = card.army;
		break;
	}
	return attrValue;
}
