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

	playerListInsert(&players, playerCreate(0, "Carlinhos", 20));
	playerListInsert(&players, playerCreate(1, "Joãozinho", 20));
	playerListInsert(&players, playerCreate(2, "xXx_gamer97_xXx", 20));
	playerListInsert(&players, playerCreate(3, "pompompurin", 20));

	int acc = 0;
	for (PlayerNode *i = players; i != NULL; i = i->next) {
		deckPush(i->data.deck, createCard(acc++, "país genérico", "América do Sul Extendida", 0, 0, 0, 0));
		deckPush(i->data.deck, createCard(acc++, "billions must play", "América do Sul Extendida", 1, 0, 0, 0));
	}

	/* Tamanho da lista */
	printf("Tamanho da lista: %d\n", playerListLen(players));

	/* Mostra os jogadores */
	printPlayerList(players);

	/* Free na lista */
	playerListFree(players);
	return 0;
}

void printPlayerList(PlayerNode *head) {
	while (head != NULL) {
		printf("------------------------\n");
		printf("Jogador: %s\n", head->data.name);
		printf("id: %d\n", head->data.id);
		printf("Número de cartas: %d\n", head->data.deck->top + 1);
		printf("Carta atual:\n");
		printCard(deckPeek(head->data.deck));
		printf("------------------------\n");
		head = head->next;
	}
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
