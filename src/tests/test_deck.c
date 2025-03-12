#include <stdio.h>

#include "../include/deck.h"
#include "../include/card.h"

void printcard(Card *card)
{
	printf("Id: %d\n", card->id);
	printf("Name: %s\n", card->name);
	printf("Category: %s\n", card->category);
	printf("Defence: %d\n", card->defence);
	printf("Army: %d\n", card->army);
	printf("Navy: %d\n", card->navy);
	printf("Airfoce: %d\n", card->airforce);
}

int main()
{
	Deck *deck = deckInitialize(3);
	Card card;

	deckPush(deck, createCard(1, "Equestria", "Equus", 12, 3, 5, 10));
	deckPush(deck, createCard(2, "Changeling Lands", "Equus", 7, 20, 10, 15));
	deckPush(deck, createCard(3, "Nova Griffonia", "Equus", 4, 8, 8, 13));

	/*
	- Important function to inform each player to update his number of cards
	in each turn. Good to increase the competition.
*/

	int total_of_cards = deckGetHeight(deck);
	printf("Total of cards in player deck: %d\n", total_of_cards);

	printf("peek:\n");
	card = deckPeek(deck);
	printcard(&card);
	printf("\n");

	printf("pop until empty:\n");
	while (!deckIsEmpty(deck))
	{
		card = deckPop(deck);
		printcard(&card);
		printf("\n");
	}

	deckFree(deck);

	return 0;
}
