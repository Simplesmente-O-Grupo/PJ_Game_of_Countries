#ifndef DECK_H
#define DECK_H
#include <stdbool.h>

#include "card.h"

/**
 * @file deck.h
 * @brief Este arquivo define um baralho para guardar cartas.
 * O baralho é uma estrutura de dados do tipo pilha.
 */

typedef struct Deck
{
	/* ponteiro permite criar baralhos de diferentes tamanhos */
	Card *cards;
	int top;
	int size;
} Deck;

/**
 * @brief Aloca dinâmicamente um baralho e retorna o ponteiro.
 *
 * @param size Altura máxima da pilha do baralho
 * @return Um ponteiro para o baralho
 */
Deck *deckInitialize(int size);

/**
 * @brief Verifica se a pilha está cheia
 *
 * @param deck Ponteiro para um baralho
 * @return Verdadeiro para se o baralho estiver cheio
 */

bool deckIsFull(Deck *deck);
/**
 * @brief Verifica se a pilha está vazia
 *
 * @param deck Ponteiro para um baralho
 * @return Verdadeiro se a pilha estiver vazia
 */
bool deckIsEmpty(Deck *deck);

/**
 * @brief Insere uma carta no topo do baralho
 *
 * @param deck Ponteiro para o baralho
 * @param card Uma carta
 * 
 * @return verdadeiro se a carta foi inserida
 * @see createCard
 */
bool deckPush(Deck *deck, Card card);

/**
 * @brief Remove a carta no topo do baralho
 *
 * @param deck Ponteiro para o baralho
 * @return A carta removida
 */
Card deckPop(Deck *deck);

/**
 * @brief Observa qual carta está no topo do baralho
 *
 * @param deck ponteiro para o baralho.
 * @return Carta no topo do baralho
 */
Card deckPeek(Deck *deck);

/**
 * @brief Observa a altura atual do baralho
 *
 * @param deck Ponteiro para o baralho
 * @return quantidade de cartas no baralho
 */
int deckGetHeight(Deck *deck);

/**
 *
 * @brief Libera toda a memória alocada pelo baralho
 *
 * @param deck Ponteiro para o baralho
 */
void deckFree(Deck *deck);

#endif
