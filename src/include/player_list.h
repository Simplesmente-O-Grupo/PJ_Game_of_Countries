#ifndef PLAYER_LIST_H
#define PLAYER_LIST_H
#include <stdbool.h>

#include "player.h"

#define MAX_PLAYERS 4

/**
 * PlayerNode é um nó de uma lista
 * encadeada circular de jogadores.
 */
typedef struct PlayerNode
{
	/**
	* Armazena o jogador
	*/
	Player data;
	/**
	 * Endereço para o próximo jogador
	 */
	struct PlayerNode *next;
} PlayerNode;

bool playerListIsEmpty(PlayerNode *head);
int playerListLen(PlayerNode *head);
bool playerListInsert(PlayerNode **head, Player player);
void playerListFree(PlayerNode **head);
void playerListRemove(PlayerNode **head, PlayerNode *target);
PlayerNode *playerListHighestAttribute(PlayerNode *head, CardAttribute attr);
bool playerListNameIsUnique(PlayerNode *head, char *str);

#endif
