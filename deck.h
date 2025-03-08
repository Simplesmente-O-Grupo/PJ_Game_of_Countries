#ifndef DECK_H
#define DECK_H
#include "card.h"

typedef struct Deck
{
	/* ponteiro permite criar baralhos de diferentes tamanhos */
	Card *cards;
	int top;
	int size;
} Deck;

Deck *deck_initialize(int size);
int deck_is_full(Deck *deck);
int deck_is_empty(Deck *deck);
int deck_push(Deck *deck, Card card);
Card deck_pop(Deck *deck);
Card deck_peek(Deck *deck);
/*
	- Important function to inform each player to update his number of cards
	in each turn. Good to increase the competition.
*/
int count_total_cards(Deck *deck);
void deck_free(Deck *deck);

#endif
