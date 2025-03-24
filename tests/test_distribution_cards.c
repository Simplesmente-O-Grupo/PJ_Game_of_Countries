#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../src/include/player.h"
#include "../src/include/deck.h"
#include "../src/include/card.h"
#include "../src/include/player_list.h"
#include "../src/include/countries.h"

void displayCard(Card card)
{
    printf("ID: %d | %s (%s) | Defesa: %d | Exército: %d | Marinha: %d | Força Aérea: %d\n",
           card.id, card.name, card.category, card.defence, card.army, card.navy, card.airforce);
}

void displayPlayerDeck(Player player)
{
    printf("\n=== Baralho do Jogador %s (ID: %d) ===\n", player.name, player.id);
    printf("Total de cartas: %d\n\n", deckGetHeight(player.deck));

    Deck *tempDeck = deckInitialize(deckGetHeight(player.deck));

    while (!deckIsEmpty(player.deck))
    {
        Card card = deckPop(player.deck);
        displayCard(card);
        deckPush(tempDeck, card);
    }

    while (!deckIsEmpty(tempDeck))
    {
        deckPush(player.deck, deckPop(tempDeck));
    }

    deckFree(tempDeck);
}

void displayAllPlayers(PlayerNode *players)
{
    PlayerNode *current = players;
    do {
        displayPlayerDeck(current->data);
        current = current->next;
    } while (current != players);
}

void displayMainDeck(Card *cards)
{
    printf("\n=== Baralho Principal ===\n");
    printf("Total de cartas: %d\n", GLOBAL_COUNTRIES_AMOUNT);

    printf("\nCartas no baralho principal:\n");

    for (int i = 0; i < GLOBAL_COUNTRIES_AMOUNT; i++)
    {
        displayCard(cards[i]);
    }

    printf("\n");
}

int main()
{
    printf("Programa iniciado.\n");

    int numPlayers = 0;
    int cardsPerPlayer = 0;

    printf("Digite o número de jogadores: ");
    if (scanf("%d", &numPlayers) != 1)
    {
        printf("Erro ao ler o número de jogadores.\n");
        return 1;
    }

    while (getchar() != '\n');

    printf("Número de jogadores: %d\n", numPlayers);

    Card *countryCards = NULL;
    printf("Inicializando a lista de países...\n");
    int success = initializeCountryList(&countryCards);
    if (!success)
    {
        printf("Error to initialize countries list.\n");
        return 1;
    }

    printf("Countries list initialized with %d cards.\n", GLOBAL_COUNTRIES_AMOUNT);

    printf("Embaralhando as cartas...\n");
    shuffle(countryCards, GLOBAL_COUNTRIES_AMOUNT);
    printf("Cards shuffled successfully!.\n");
    

    cardsPerPlayer = GLOBAL_COUNTRIES_AMOUNT / numPlayers;
    printf("Cartas por jogador: %d\n", cardsPerPlayer);

    PlayerNode *playerList = NULL;

    for (int i = 0; i < numPlayers; i++)
    {
        char playerName[PLAYER_NAME_MAXLEN];
        printf("Player name %d: ", i + 1);

        // Usa fgets para ler o nome do jogador
        fgets(playerName, PLAYER_NAME_MAXLEN, stdin);

        // Remove o '\n' do final da string, se existir
        size_t len = strlen(playerName);
        if (len > 0 && playerName[len - 1] == '\n')
        {
            playerName[len - 1] = '\0';
        }

        // Converte o nome para maiúsculas
        for (int j = 0; playerName[j]; j++)
        {
            playerName[j] = toupper(playerName[j]);
        }

        printf("Criando jogador %s...\n", playerName);
        Player newPlayer = playerCreate(i + 1, playerName);
        if (newPlayer.deck == NULL)
        {
            printf("Error to create player.\n");
            freeCountryList(&countryCards);
            playerListFree(&playerList);
            return 1;
        }

        printf("Adicionando jogador à lista...\n");
        if (!playerListInsert(&playerList, newPlayer))
        {
            printf("Erro ao adicionar jogador à lista.\n");
            playerDestroy(&newPlayer);
            freeCountryList(&countryCards);
            playerListFree(&playerList);
            return 1;
        }
    }

    printf("Distribuindo cartas...\n");
    if (distributeCards(countryCards, playerList))
    {
        printf("\nCards distributed successfully!\n");

        displayMainDeck(countryCards);

        displayAllPlayers(playerList);
    }
    else
    {
        printf("Error to distribute cards.\n");
    }

    printf("Liberando memória...\n");
    freeCountryList(&countryCards);
    playerListFree(&playerList);

    printf("Programa finalizado.\n");
    return 0;
}
