#include <stdio.h>

#include "../include/player.h"
#include "../include/player_list.h"
#include "../include/card.h"
#include "../include/deck.h"

void printPlayerList(PlayerNode *head);
void printCard(Card card);

int main() {
	PlayerNode *players = NULL;

	/* Criando e adicionando jogadores
	* à lista. */

	playerListInsert(&players, playerCreate(0, "Carlinhos"));
	playerListInsert(&players, playerCreate(1, "Joãozinho"));
	playerListInsert(&players, playerCreate(2, "xXx_gamer97_xXx"));
	playerListInsert(&players, playerCreate(3, "pompompurin"));

	int acc = 0;
	PlayerNode *i = players;
	do {
		deckPush(i->data.deck, createCard(acc++, "país genérico", "América do Sul Extendida", 0, 0, 0, 0));
		deckPush(i->data.deck, createCard(acc++, "billions must play", "América do Sul Extendida", 1, 0, 0, 0));
		i = i->next;
	} while (i != players);

	/* Tamanho da lista */
	printf("Tamanho da lista: %d\n", playerListLen(players));

	/* Mostra os jogadores */
	printPlayerList(players);

	/* Free na lista */
	playerListFree(&players);
	return 0;
}

void printPlayerList(PlayerNode *head) {
	PlayerNode *temp = head;
	do {
		printf("------------------------\n");
		printf("Jogador: %s\n", temp->data.name);
		printf("id: %d\n", temp->data.id);
		printf("Número de cartas: %d\n", temp->data.deck->top + 1);
		printf("Carta atual:\n");
		printCard(deckPeek(temp->data.deck));
		printf("------------------------\n");
		temp = temp->next;
	} while(temp != head);
}

void printCard(Card card) {
	printf("\tid: %d\n", card.id);
	printf("\tnome: %s\n", card.name);
	printf("\tcategoria: %s\n", card.category);
	printf("\tdefesa: %d\n", card.defence);
	printf("\texército: %d\n", card.army);
	printf("\tmarinha: %d\n", card.navy);
	printf("\tforça aérea: %d\n", card.airforce);
}
