#ifndef PLAYER_H
#define PLAYER_H
#include "deck.h"

#define PLAYER_NAME_MAXLEN 50

typedef struct Player
{
	int id;
	char name[PLAYER_NAME_MAXLEN];
	Deck *deck;
} Player;

Player playerCreate(int id, const char *name);
void playerTransferCard(Player *dest, Player *src);
void playerDestroy(Player *player);

#endif
