#include <stdlib.h>
#include <stdio.h>

#include "player.h"
#include "player_list.h"

int playerListIsEmpty(PlayerNode *head) {
	return head == NULL;
}

int playerListLen(PlayerNode *head) {
	int acc = 0;
	while (head != NULL) {
		acc++;
		head = head->next;
	}
	return acc;
}

int playerListInsert(PlayerNode **head, Player player) {
	PlayerNode *tail = malloc(sizeof(PlayerNode));
	if (tail == NULL) {
		return 0;
	}

	tail->data = player;
	tail->next = NULL;

	if (playerListIsEmpty(*head)) {
		*head = tail;
		return 0;
	}

	PlayerNode *i = *head;
	while (i->next != NULL) {
		i = i->next;
	}
	i->next = tail;

	return 1;
}

/* Não preciso me preocupar em remover itens arbritrários da lista */

void playerListFree(PlayerNode *head) {
	PlayerNode *tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		playerDestroy(&(tmp->data));
		free(tmp);
	}
}
