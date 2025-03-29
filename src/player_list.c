#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "include/player.h"
#include "include/player_list.h"
/*verifica se a lista de jogadores está vazia*/
bool playerListIsEmpty(PlayerNode *head)
{
	return head == NULL;
}
/*Calcula o número de jogadores na lista.*/
int playerListLen(PlayerNode *head)
{
	/*percorre a lista circularmente com um ponteiro temporário
	somando 1 a cada nó até voltar ao início da lista*/
	int acc = 0;
	PlayerNode *temp = head;
	do {
		acc++;
		temp = temp->next;
	} while (temp != head);
	return acc; //retorna o número de jogadores
}
/*insere um jogador na lista circular*/
bool playerListInsert(PlayerNode **head, Player player)
{
	PlayerNode *tail = malloc(sizeof(PlayerNode));
	if (tail == NULL)
	{
		return false;
	}
	tail->data = player;
	/* Caso especial: a lista está vazia */
	if (playerListIsEmpty(*head))
	{
		*head = tail; //O novo nó se torna o primeiro e aponta para si mesmo
		(*head)->next = *head;
		return true;
	}

	/* Caso genérico */
	PlayerNode *i = *head;
	while (i->next != *head)
	{
		i = i->next;
	}
	i->next = tail;
	tail->next = *head;

	return true;
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

	/* Caso genérico,
	novo nó é inserido após o último nó e mantém a circularidade*/
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
/*libera a memória*/
void playerListFree(PlayerNode **head)
{
	/*verifica se a lista está vazia*/
	if (playerListIsEmpty(*head)) return;

	PlayerNode *current = *head;
	PlayerNode *next;
	do {
		next = current->next;
		playerDestroy(&current->data);//libera a memória do jogador
		free(current);
		current = next;
	} while (current != *head);
	*head = NULL;
}
/*identifica o maior atributod as cartas do jogador*/
PlayerNode *playerListHighestAttribute(PlayerNode *head, CardAttribute attr) {
	PlayerNode *temp = head;
	PlayerNode *winner;
	int tie = 0;
	int highestAttrValue = 0;
	do {
		/*verifica se os jogadores tem cartas*/
		if (deckGetHeight(temp->data.deck) > 0) {
			int currAttrValue;
			/*verifica qual atributo é o maior da carta selecionada*/
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
			/*verifica qual tem o maior atributo*/
			if (highestAttrValue < currAttrValue) {
				highestAttrValue = currAttrValue;
				tie = 0;
				/* Atualiza o vencedor */
				winner = temp;
			} else if (highestAttrValue == currAttrValue) {
				/* Empate, não há vencedores */
				tie = 1;
			}
			/* temp debug */
			//printf("%s: %s - %d\n", temp->data.name, deckPeek(temp->data.deck).name, currAttrValue);
		}
		temp = temp->next;
	} while(temp != head);

	if (tie || highestAttrValue == 0) {
		return NULL;
	}
	return winner;
}
/*verifica se o nome do jogador é único*/
bool playerListNameIsUnique(PlayerNode *head, char *str) {
	PlayerNode *temp = head;
	/* Caso especial: Não há jogadores */
	if (playerListIsEmpty(head)) return true;
	do {
		if (strcmp(temp->data.name, str) == 0) {
			return false;
		}
		temp = temp->next;
	} while(temp != head);
	return true;
}
