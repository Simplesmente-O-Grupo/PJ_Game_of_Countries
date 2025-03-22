#ifndef TURN_GAME_H
#define TURN_GAME_H

void displayHelpMenu();
void turnGame();
PlayerNode *handleBattle(PlayerNode *currentPlayer, PlayerNode *playerList, int chooseAttribute, Deck *battleDeck);
PlayerNode *handleWar(PlayerNode *playerList, int chooseAttribute, Deck *battleDeck);
void eliminatePlayer();
void checkGameOver();
int countPlayersWithCards();

#endif