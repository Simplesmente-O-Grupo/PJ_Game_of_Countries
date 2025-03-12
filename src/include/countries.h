#ifndef COUNTRIES_H
#define COUNTRIES_H
#include "card.h"

#define GLOBAL_COUNTRIES_AMOUNT 80

int initializeCountryList(Card **cards);

void printCardsValue(Card *cards);
void shuffle(Card *cards, int size);
void freeCountryList(Card **cards);
#endif
