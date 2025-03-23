#ifndef COUNTRIES_H
#define COUNTRIES_H
#include "card.h"
#include "player_list.h"

#define GLOBAL_COUNTRIES_AMOUNT 7

int initializeCountryList(Card **cards);

void printCardsValue(Card *cards);
void shuffle(Card *cards, int size);
void freeCountryList(Card **cards);
int distributeCards(Card *cards, PlayerNode *players);
#endif
