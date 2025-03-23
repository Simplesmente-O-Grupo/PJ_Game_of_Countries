#ifndef TURN_GAME_H
#define TURN_GAME_H
#include "player_list.h"
#include "deck.h"

void displayHelpMenu();
void turnGame();
PlayerNode *handleBattle(PlayerNode *currentPlayer, PlayerNode *playerList, int chosenAttribute, Deck *battleDeck);
PlayerNode *handleWar(PlayerNode *playerList, int chosenAttribute, Deck *battleDeck);
void eliminatePlayer();
void checkGameOver();
int countPlayersWithCards();

#endif
