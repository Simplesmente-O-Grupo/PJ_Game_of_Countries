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

Deck *deckInitialize(int size);
int deckIsFull(Deck *deck);
int deckIsEmpty(Deck *deck);
int deckPush(Deck *deck, Card card);
Card deckPop(Deck *deck);
Card deckPeek(Deck *deck);
/*
	- Important function to inform each player to update his number of cards
	in each turn. Good to increase the competition.
*/
int deckGetHeight(Deck *deck);
void deckFree(Deck *deck);

#endif
