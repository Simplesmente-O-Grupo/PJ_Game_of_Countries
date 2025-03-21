#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "include/deck.h"
#include "include/card.h"

/*
Aqui, deck é um ponteiro para Deck (Deck *), e o operador sizeof(deck) retorna o tamanho de um ponteiro, não da estrutura Deck. Em um sistema de 64 bits, por exemplo, sizeof(deck) pode ser 8 bytes (tamanho de um ponteiro), enquanto sizeof(Deck) pode ser muito maior (dependendo dos campos da struct).

Isso significa que a alocação pode estar reservando menos memória do que o necessário, o que pode levar a comportamento indefinido e bugs difíceis de detectar.
*/

/* Cria um baralho de tamanho arbritrário */
Deck *deckInitialize(int size)
{
	Deck *deck = malloc(sizeof(Deck));
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

int deckGetHeight(Deck *deck)
{
	return deck->top + 1;
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
