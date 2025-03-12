#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "include/deck.h"
#include "include/card.h"

/* Cria um baralho de tamanho arbritrário */
Deck *deckInitialize(int size)
{
	Deck *deck = malloc(sizeof(deck));
	if (deck == NULL)
	{
		fprintf(stderr, "[ERR]: Impossível alocar deck.\n");
		return NULL;
	}

	deck->top = -1;
	deck->size = size;

	Card *cards = malloc(sizeof(Card) * size);

	if (cards == NULL)
	{
		fprintf(stderr, "[ERR]: Impossível alocar deck.\n");
		free(deck);
		return NULL;
	}

	deck->cards = cards;

	return deck;
}

int deckIsFull(Deck *deck)
{
	return deck->top == deck->size - 1;
}

int deckIsEmpty(Deck *deck)
{
	return deck->top == -1;
}

int deckPush(Deck *deck, Card card)
{
	if (deckIsFull(deck))
	{
		return 0;
	}

	deck->cards[++deck->top] = card;
	return 1;
}

/*
	- Important function to inform each player to update his number of cards
	in each turn. Good to increase the competition.
*/

int countTotalCards(Deck *deck)
{

	int total_of_cards = 0;

	for (int i = 0; i <= deck->top; i++)
	{
		total_of_cards++;
	}

	return total_of_cards;
}

/* É esperado que se verifique se
 * o baralho está vazio antes de chamar a função
 */
Card deckPop(Deck *deck)
{
	assert(!deckIsEmpty(deck));

	return deck->cards[deck->top--];
}

Card deckPeek(Deck *deck)
{
	assert(!deckIsEmpty(deck));

	return deck->cards[deck->top];
}

void deckFree(Deck *deck)
{
	free(deck->cards);
	free(deck);
}
