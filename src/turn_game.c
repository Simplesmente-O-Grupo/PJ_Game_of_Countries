#include <stdio.h>
#include <stdlib.h>

#include "player_list.h"
#include "countries.h"
#include "card.h"
#include "deck.h"
#include "player.h"
#include "turn_game.h"

void turnGame(Player *player)
{
    if (deckIsEmpty(player->deck))
    {
        printf("Player Deck Empty.\n");
    }

    Card currentCard = deckPeek(player->deck);
    printf("\n Player Turn \n: %s", player->name);
    printf("Card: \n");
    printCard(currentCard);
}

void displayOptions()
{
}

void printCard(Card card)
{
    printf("\tid: %d\n", card.id);
    printf("\tnome: %s\n", card.name);
    printf("\tcategoria: %s\n", card.category);
    printf("\tdefesa: %d\n", card.defence);
    printf("\texército: %d\n", card.army);
    printf("\tmarinha: %d\n", card.navy);
    printf("\tforça aérea: %d\n", card.airforce);
}