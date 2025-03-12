#include <stdint.h>
#include "include/number_of_players.h"

int define_number_of_players(int number_players)
{
    number_players = 0;

    do
    {
        printf("Players: ");

        if (scanf("%d", number_players != 1))
        {
            printf("Invalid Value!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (number_players == 0 || number_players > MAX_PLAYERS)
        {
            printf("Number invalid! Type a valid value!");
        }
    } while (number_players == 0 || number_players > MAX_PLAYERS);

    printf("Number of players: %d\n", number_players);

    return number_players;
}
