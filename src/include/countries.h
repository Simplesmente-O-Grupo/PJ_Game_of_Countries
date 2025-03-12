#ifndef COUNTRIES_H
#define COUNTRIES_H
#include "card.h"

#define GLOBAL_COUNTRIES_AMOUNT 80

int initialize_country_list(Card **cards);

void print_cards_value(Card *cards);
void shuffle(Card *cards, int size);
void free_country_list(Card **cards);
#endif
