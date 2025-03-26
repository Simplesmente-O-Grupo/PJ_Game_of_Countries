#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "include/player.h"
#include "include/player_list.h"

int playerListIsEmpty(PlayerNode *head)
{
	return head == NULL;
}

int playerListLen(PlayerNode *head)
{
	int acc = 0;
	PlayerNode *temp = head;
	do {
		acc++;
		temp = temp->next;
	} while (temp != head);
	return acc;
}

int playerListInsert(PlayerNode **head, Player player)
{
	PlayerNode *tail = malloc(sizeof(PlayerNode));
	if (tail == NULL)
	{
		return 0;
	}

	tail->data = player;

	/* Caso especial: a lista está vazia */
	if (playerListIsEmpty(*head))
	{
		*head = tail;
		(*head)->next = *head;
		return 1;
	}

	/* Caso genérico */
	PlayerNode *i = *head;
	while (i->next != *head)
	{
		i = i->next;
	}
	i->next = tail;
	tail->next = *head;

	return 1;
}

void playerListRemove(PlayerNode **head, PlayerNode *target) {
	if(playerListIsEmpty(*head)) return;

	PlayerNode *temp = *head;

	if (target == *head) {
		/* Caso especial: A lista só tem um membro */
		if (temp->next == *head) {
			playerDestroy(&(*head)->data);
			free(*head);
			*head = NULL;
			return;
		}

		/* Caso especial: O alvo é head */
		while (temp->next != *head) {
			temp = temp->next;
		}
		temp->next = (*head)->next;

		playerDestroy(&(*head)->data);
		free(*head);

		*head = temp->next;
		return;
	}

	/* Caso genérico */
	PlayerNode *prev;
	while (temp->next != *head) {
		prev = temp;
		temp = temp->next;
		if (temp == target) {
			prev->next = temp->next;
			playerDestroy(&temp->data);
			free(temp);
		}
	}
}

void playerListFree(PlayerNode **head)
{
	if (playerListIsEmpty(*head)) return;

	PlayerNode *current = *head;
	PlayerNode *next;
	do {
		next = current->next;
		playerDestroy(&current->data);
		free(current);
		current = next;
	} while (current != *head);
	*head = NULL;
}

PlayerNode *playerListHighestAttribute(PlayerNode *head, CardAttribute attr) {
	PlayerNode *temp = head;
	PlayerNode *winner;
	int tie = 0;
	int highestAttrValue = 0;
	do {
		if (deckGetHeight(temp->data.deck) > 0) {
			int currAttrValue;
			Card currCard = deckPeek(temp->data.deck);
			switch(attr) {
				case ARMY:
					currAttrValue = currCard.army;
					break;
				case DEFENCE:
					currAttrValue = currCard.defence;
					break;
				case NAVY:
					currAttrValue = currCard.navy;
					break;
				case AIRFORCE:
					currAttrValue = currCard.airforce;
					break;
			}
			if (highestAttrValue < currAttrValue) {
				highestAttrValue = currAttrValue;
				tie = 0;
				winner = temp;
			} else if (highestAttrValue == currAttrValue) {
				/* Empate, não há vencedores */
				tie = 1;
			}
			/* temp debug */
			printf("%s: %s - %d\n", temp->data.name, deckPeek(temp->data.deck).name, currAttrValue);
		}
		temp = temp->next;
	} while(temp != head);

	if (tie || highestAttrValue == 0) {
		return NULL;
	}
	return winner;
}

int playerListNameIsUnique(PlayerNode *head, char *str) {
	PlayerNode *temp = head;
	/* Caso especial: Não há jogadores */
	if (playerListIsEmpty(head)) return 1;
	do {
		if (strcmp(temp->data.name, str) == 0) {
			return 0;
		}
		temp = temp->next;
	} while(temp != head);
	return 1;
}
