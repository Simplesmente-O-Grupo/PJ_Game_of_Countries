#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "deck.h"
#include "card.h"

/* Cria um baralho de tamanho arbritrário */
Deck *deck_initialize(int size)
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

int deck_is_full(Deck *deck)
{
	return deck->top == deck->size - 1;
}

int deck_is_empty(Deck *deck)
{
	return deck->top == -1;
}

int deck_push(Deck *deck, Card card)
{
	if (deck_is_full(deck))
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

int count_total_cards(Deck *deck)
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
Card deck_pop(Deck *deck)
{
	assert(!deck_is_empty(deck));

	return deck->cards[deck->top--];
}

Card deck_peek(Deck *deck)
{
	assert(!deck_is_empty(deck));

	return deck->cards[deck->top];
}

void deck_free(Deck *deck)
{
	free(deck->cards);
	free(deck);
}
