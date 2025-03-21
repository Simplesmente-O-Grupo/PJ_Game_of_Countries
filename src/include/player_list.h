#ifndef PLAYER_LIST_H
#define PLAYER_LIST_H
#include "deck.h"
#include "player.h"

#define MAX_PLAYERS 4

typedef struct PlayerNode {
	Player data; 
	struct PlayerNode *next;
} PlayerNode;

int playerListIsEmpty(PlayerNode *head);
int playerListLen(PlayerNode *head);
int playerListInsert(PlayerNode **head, Player player);
void playerListFree(PlayerNode *head);

#endif
