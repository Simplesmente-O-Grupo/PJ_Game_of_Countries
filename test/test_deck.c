#include <stdio.h>

#include "../deck.h"
#include "../card.h"

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
	Deck *deck = deck_initialize(3);
	Card card;

	deck_push(deck, create_card(1, "Equestria", "Equus", 12, 3, 5, 10));
	deck_push(deck, create_card(2, "Changeling Lands", "Equus", 7, 20, 10, 15));
	deck_push(deck, create_card(3, "Nova Griffonia", "Equus", 4, 8, 8, 13));

	/*
	- Important function to inform each player to update his number of cards
	in each turn. Good to increase the competition.
*/

	int total_of_cards = count_total_cards(deck);
	printf("Total of cards in player deck: %d\n", total_of_cards);

	printf("peek:\n");
	card = deck_peek(deck);
	printcard(&card);
	printf("\n");

	printf("pop until empty:\n");
	while (!deck_is_empty(deck))
	{
		card = deck_pop(deck);
		printcard(&card);
		printf("\n");
	}

	deck_free(deck);

	return 0;
}
