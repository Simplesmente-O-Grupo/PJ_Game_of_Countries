#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/deck.h"
#include "include/card.h"

/*
 ► Aqui, deck é um ponteiro para Deck (Deck *).
 ► O operador sizeof(deck) retorna o tamanho de um ponteiro, não da estrutura Deck.
 Em um sistema de 64 bits, por exemplo, sizeof(deck) pode ser 8 bytes
 (tamanho de um ponteiro), enquanto sizeof(Deck)
 pode ser muito maior (dependendo dos campos da struct).
► Isso significa que a alocação pode estar reservando
menos memória do que o necessário,
o que pode levar a comportamento indefinido e
bugs difíceis de detectar.
*/

/* Cria um deck de tamanho arbritrário */
Deck *deckInitialize(int size)
{
	/* ► Aloca dinamicamente memória para o Deck*/
	Deck *deck = malloc(sizeof(Deck));
	if (deck == NULL)
	{
		fprintf(stderr, "[ERR]: Impossível alocar deck.\n");
		return NULL;
	}

	/* ► Indicando que o deck inicia vazio,
	 ► Definindo o tamanho máximo do deck.
	*/
	deck->top = -1;
	deck->size = size;

	/* ► Aloca dinamicamente memória para uma carta.*/
	Card *cards = malloc(sizeof(Card) * size);

	if (cards == NULL)
	{
		fprintf(stderr, "[ERR]: Impossível alocar deck.\n");
		free(deck);
		return NULL;
	}

	/* ► Atribui a carta ao deck.
	   ► retorna o deck.
	*/
	deck->cards = cards;

	return deck;
}

/* ► Checagem booleana para deck full:
Retornando 1 se o topo do deck é igual ao tamanho máximo.*/
bool deckIsFull(Deck *deck)
{
	return deck->top == deck->size - 1;
}

/* ► Checagem booleana para deck vazio:
Retornando 1 se o topo do deck é igual a uma posição antes da primeira.*/
bool deckIsEmpty(Deck *deck)
{
	return deck->top == -1;
}

/* ► Adicionar uma carta ao deck:
Checando se deck está full.
Incrementa top antes de adicionar uma carta.
Retornando true se bem sucedido.*/
bool deckPush(Deck *deck, Card card)
{
	if (deckIsFull(deck))
	{
		return false;
	}

	deck->cards[++deck->top] = card;
	return true;
}

/*
► Retornar a quantidade de cartas do deck:
Top + 1 pois o deck foi iniciado com o valor -1.
*/
int deckGetHeight(Deck *deck)
{
	return deck->top + 1;
}

/*
► Retirar uma carta do topo:
Verifica se o deck está vazio antes de retirar.
Primeiro retorna a carta do topo e depois decrementa o índice.
 */
Card deckPop(Deck *deck)
{
	assert(!deckIsEmpty(deck));

	return deck->cards[deck->top--];
}

/*
► Verifica se o deck está vazio.
► Retorna a carta do topo sem removê-la.
*/
Card deckPeek(Deck *deck)
{
	assert(!deckIsEmpty(deck));

	return deck->cards[deck->top];
}

/*
► Libera a memória para o deck e as cartas.
► Evita vazamento de memória ao liberar deck->cards antes de deck.
*/
void deckFree(Deck *deck)
{
	free(deck->cards);
	free(deck);
}
