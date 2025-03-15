#ifndef DISTRIBUTION_CARD_H
#define DISTRIBUTION_CARD_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "player.h"
#include "deck.h"
#include "card.h"
#include "number_of_players.h"
#include "player_list.h"
#include "countries.h"

int distributeCards(Deck *mainDeck, PlayerNode *players, int cardsPerPlayer);
void displayCard(Card card);
void displayPlayerDeck(Player player);
void displayAllPlayers(PlayerNode *players);
void displayMainDeck(Deck *deck, int showCards);

#endif