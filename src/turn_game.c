#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/player.h"
#include "../include/deck.h"
#include "../include/card.h"
#include "../include/player_list.h"
#include "../include/countries.h"
#include "../include/turn_game.h"

// Função para exibir uma carta
void displayCard(Card card)
{
    printf("ID: %d | %s (%s) | Defesa: %d | Exército: %d | Marinha: %d | Força Aérea: %d\n",
           card.id, card.name, card.category, card.defence, card.army, card.navy, card.airforce);
}

// Função para exibir o baralho de um jogador
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

// Função para exibir o baralho de todos os jogadores
void displayAllPlayers(PlayerNode *players)
{
    PlayerNode *current = players;
    while (current != NULL)
    {
        displayPlayerDeck(current->data);
        current = current->next;
    }
}

// Função para exibir o baralho principal
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

// Função para lidar com uma batalha
PlayerNode *handleBattle(PlayerNode *currentPlayer, PlayerNode *playerList, int chooseAttribute, Deck *battleDeck)
{
    // Adiciona a carta do jogador atual ao baralho de batalha
    Card currentPlayerCard = deckPop(currentPlayer->data.deck);
    deckPush(battleDeck, currentPlayerCard);

    PlayerNode *winningPlayer = currentPlayer;
    int highestValue = 0;
    int tieFlag = 0;

    // Inicializa o valor mais alto com o atributo escolhido do jogador atual
    switch (chooseAttribute)
    {
    case 1:
        highestValue = currentPlayerCard.airforce;
        break;
    case 2:
        highestValue = currentPlayerCard.navy;
        break;
    case 3:
        highestValue = currentPlayerCard.defence;
        break;
    case 4:
        highestValue = currentPlayerCard.army;
        break;
    default:
        break;
    }

    printf("\n--- BATTLE RESULTS ---\n");
    printf("%s: %s - %d\n", currentPlayer->data.name, currentPlayerCard.name, highestValue);

    // Compara com as cartas dos outros jogadores
    PlayerNode *otherPlayer = playerList;
    while (otherPlayer != NULL)
    {
        if (otherPlayer == currentPlayer)
        {
            otherPlayer = otherPlayer->next;
            continue; // Pula o jogador atual
        }

        if (deckIsEmpty(otherPlayer->data.deck))
        {
            printf("%s has no cards to play.\n", otherPlayer->data.name);
            otherPlayer = otherPlayer->next;
            continue; // Pula jogadores sem cartas
        }

        // Adiciona a carta do outro jogador ao baralho de batalha
        Card otherPlayerCard = deckPop(otherPlayer->data.deck);
        deckPush(battleDeck, otherPlayerCard);

        int otherAttributeValue = 0;
        switch (chooseAttribute)
        {
        case 1:
            otherAttributeValue = otherPlayerCard.airforce;
            break;
        case 2:
            otherAttributeValue = otherPlayerCard.navy;
            break;
        case 3:
            otherAttributeValue = otherPlayerCard.defence;
            break;
        case 4:
            otherAttributeValue = otherPlayerCard.army;
            break;
        default:
            break;
        }

        printf("%s: %s - %d\n", otherPlayer->data.name, otherPlayerCard.name, otherAttributeValue);

        // Verifica se há um novo vencedor ou empate
        if (otherAttributeValue > highestValue)
        {
            highestValue = otherAttributeValue;
            winningPlayer = otherPlayer;
            tieFlag = 0; // Reseta a flag de empate
        }
        else if (otherAttributeValue == highestValue)
        {
            tieFlag = 1; // Define a flag de empate
        }

        otherPlayer = otherPlayer->next;
    }

    // Verifica se houve empate
    if (tieFlag)
    {
        printf("\nIt's a TIE! Starting a WAR round...\n");
        return handleWar(playerList, chooseAttribute, battleDeck);
    }
    else
    {
        printf("\n%s WINS this round with %d!\n", winningPlayer->data.name, highestValue);

        // Adiciona todas as cartas do baralho de batalha ao baralho do vencedor
        while (!deckIsEmpty(battleDeck))
        {
            Card wonCard = deckPop(battleDeck);
            deckPush(winningPlayer->data.deck, wonCard);
        }

        printf("%s now has %d cards.\n", winningPlayer->data.name, deckGetHeight(winningPlayer->data.deck));
        return winningPlayer;
    }
}

// Função para lidar com uma guerra
PlayerNode *handleWar(PlayerNode *playerList, int chooseAttribute, Deck *battleDeck)
{
    int tieFlag = 1;
    PlayerNode *winningPlayer = NULL;
    int highestValue = 0;

    while (tieFlag)
    {
        printf("\n--- WAR ROUND ---\n");
        tieFlag = 0;
        highestValue = 0;

        // Cada jogador joga uma nova carta no baralho de batalha
        PlayerNode *warPlayer = playerList;
        while (warPlayer != NULL)
        {
            if (deckIsEmpty(warPlayer->data.deck))
            {
                printf("%s has no cards to play and is out of the game.\n", warPlayer->data.name);
                warPlayer = warPlayer->next;
                continue; // Pula jogadores sem cartas
            }

            Card warCard = deckPop(warPlayer->data.deck);
            deckPush(battleDeck, warCard);

            printf("%s played: %s\n", warPlayer->data.name, warCard.name);
            warPlayer = warPlayer->next;
        }

        // Compara as cartas jogadas na guerra
        warPlayer = playerList;
        while (warPlayer != NULL)
        {
            if (deckIsEmpty(warPlayer->data.deck))
            {
                warPlayer = warPlayer->next;
                continue; // Pula jogadores sem cartas
            }

            int warAttributeValue = 0;
            switch (chooseAttribute)
            {
            case 1:
                warAttributeValue = deckPeek(battleDeck).airforce;
                break;
            case 2:
                warAttributeValue = deckPeek(battleDeck).navy;
                break;
            case 3:
                warAttributeValue = deckPeek(battleDeck).defence;
                break;
            case 4:
                warAttributeValue = deckPeek(battleDeck).army;
                break;
            default:
                break;
            }

            printf("%s: %s - %d\n", warPlayer->data.name, deckPeek(battleDeck).name, warAttributeValue);

            // Verifica se há um novo vencedor ou empate
            if (warAttributeValue > highestValue)
            {
                highestValue = warAttributeValue;
                winningPlayer = warPlayer;
                tieFlag = 0; // Reseta a flag de empate
            }
            else if (warAttributeValue == highestValue)
            {
                tieFlag = 1; // Define a flag de empate
            }

            warPlayer = warPlayer->next;
        }

        if (tieFlag)
        {
            printf("\nAnother TIE! Continuing the WAR...\n");
        }
    }

    printf("\n%s WINS the WAR with %s = %d!\n", winningPlayer->data.name,
           (chooseAttribute == 1 ? "Airforce" : chooseAttribute == 2 ? "Navy"
                                            : chooseAttribute == 3   ? "Defence"
                                                                     : "Army"),
           highestValue);

    // Adiciona todas as cartas do baralho de batalha ao baralho do vencedor
    int cardsWon = 0;
    while (!deckIsEmpty(battleDeck))
    {
        Card wonCard = deckPop(battleDeck);
        deckPush(winningPlayer->data.deck, wonCard);
        cardsWon++;
    }

    printf("%s now has %d cards (ganhou %d nesta rodada).\n",
           winningPlayer->data.name, deckGetHeight(winningPlayer->data.deck), cardsWon);

    return winningPlayer;
}

// Função para eliminar um jogador
void eliminatePlayer(PlayerNode **playerList, PlayerNode *player)
{
    if (*playerList == NULL || player == NULL)
        return;

    if (*playerList == player)
    {
        *playerList = player->next;
        playerDestroy(&player->data);
        free(player);
        return;
    }

    PlayerNode *temp = *playerList;
    while (temp->next != NULL && temp->next != player)
    {
        temp = temp->next;
    }

    if (temp->next == player)
    {
        temp->next = player->next;
        playerDestroy(&player->data);
        free(player);
    }
}

// Função para verificar se o jogo acabou
void checkGameOver(PlayerNode *playerList)
{
    int playersWithCards = 0;
    PlayerNode *winner = NULL;
    PlayerNode *temp = playerList;

    while (temp != NULL)
    {
        if (!deckIsEmpty(temp->data.deck))
        {
            playersWithCards++;
            winner = temp;
        }
        temp = temp->next;
    }

    if (playersWithCards == 1)
    {
        printf("\n%s WINS THE GAME with %d cards!\n", winner->data.name, deckGetHeight(winner->data.deck));
        exit(0);
    }
}

// Função principal do jogo
void turnGame(Card *card, PlayerNode *playerList)
{
    static PlayerNode *currentPlayer = NULL;

    // Inicializa o currentPlayer se for NULL
    if (currentPlayer == NULL)
    {
        currentPlayer = playerList;
    }

    // Verifica se há jogadores na lista
    if (currentPlayer == NULL)
    {
        printf("No players in the list!\n");
        return;
    }

    printf("\n*** %s's Turn ***\n", currentPlayer->data.name);

    // Verifica se o jogador atual tem cartas
    if (deckIsEmpty(currentPlayer->data.deck))
    {
        printf("Player has no cards left.\n");
        eliminatePlayer(&playerList, currentPlayer);
        currentPlayer = currentPlayer->next;
        if (currentPlayer == NULL)
        {
            currentPlayer = playerList; // Volta ao início da lista
        }
        return;
    }

    // Exibe a carta do topo do baralho do jogador atual
    Card peekCard = deckPeek(currentPlayer->data.deck);
    printf("Your top card is:\n");
    displayCard(peekCard);

    // Solicita ao jogador que escolha um atributo
    int chooseAttribute = 0;
    printf("\nChoose an attribute to battle with:\n");
    printf("1) Airforce (%d)\n", peekCard.airforce);
    printf("2) Navy (%d)\n", peekCard.navy);
    printf("3) Defence (%d)\n", peekCard.defence);
    printf("4) Army (%d)\n", peekCard.army);

    if (scanf("%d", &chooseAttribute) != 1 || chooseAttribute < 1 || chooseAttribute > 4)
    {
        printf("Invalid choice. Defaulting to Airforce.\n");
        chooseAttribute = 1;
    }

    // Cria um baralho temporário para a batalha
    Deck *battleDeck = deckInitialize(GLOBAL_COUNTRIES_AMOUNT);
    if (battleDeck == NULL)
    {
        printf("Error: Failed to allocate memory for battle deck.\n");
        return;
    }

    // Executa a batalha
    PlayerNode *winner = handleBattle(currentPlayer, playerList, chooseAttribute, battleDeck);
    deckFree(battleDeck);

    // Atualiza o currentPlayer para o próximo jogador
    if (winner != NULL)
    {
        currentPlayer = winner;
    }
    else
    {
        currentPlayer = currentPlayer->next;
        if (currentPlayer == NULL)
        {
            currentPlayer = playerList; // Volta ao início da lista
        }
    }

    // Verifica se o jogo acabou
    checkGameOver(playerList);
}

// Função para exibir o menu de ajuda
void displayHelpMenu()
{
    printf("\n=== HELP MENU ===\n");
    printf("1. Each player chooses an attribute to battle with.\n");
    printf("2. The player with the highest attribute value wins the round.\n");
    printf("3. In case of a tie, a WAR round begins.\n");
    printf("4. The game ends when only one player has cards left.\n");
    printf("==================\n");
}

// Função principal
int main()
{
    printf("Programa iniciado.\n");
    displayHelpMenu();

    int numPlayers = 0;
    while (1)
    {
        printf("Digite o número de jogadores (mínimo 2): ");
        if (scanf("%d", &numPlayers) == 1 && numPlayers >= 2)
        {
            break;
        }
        else
        {
            printf("Entrada inválida. Por favor, insira um número inteiro maior ou igual a 2.\n");
            while (getchar() != '\n')
                ;
        }
    }

    while (getchar() != '\n')
        ;

    printf("Número de jogadores: %d\n", numPlayers);

    Card *countryCards = NULL;
    printf("Inicializando a lista de países...\n");
    if (!initializeCountryList(&countryCards))
    {
        printf("Erro ao inicializar a lista de países.\n");
        return 1;
    }

    printf("Lista de países inicializada com %d cartas.\n", GLOBAL_COUNTRIES_AMOUNT);

    printf("Embaralhando as cartas...\n");
    shuffle(countryCards, GLOBAL_COUNTRIES_AMOUNT);
    printf("Cartas embaralhadas com sucesso!\n");

    int cardsPerPlayer = GLOBAL_COUNTRIES_AMOUNT / numPlayers;
    printf("Cartas por jogador: %d\n", cardsPerPlayer);

    PlayerNode *playerList = NULL;

    for (int i = 0; i < numPlayers; i++)
    {
        char playerName[PLAYER_NAME_MAXLEN];
        printf("Nome do jogador %d: ", i + 1);

        if (fgets(playerName, PLAYER_NAME_MAXLEN, stdin) != NULL)
        {
            size_t len = strlen(playerName);
            if (len > 0 && playerName[len - 1] == '\n')
            {
                playerName[len - 1] = '\0';
            }
            else
            {
                while (getchar() != '\n')
                    ;
            }

            for (int j = 0; playerName[j]; j++)
            {
                playerName[j] = toupper(playerName[j]);
            }

            printf("Criando jogador %s...\n", playerName);
            Player newPlayer = playerCreate(i + 1, playerName, cardsPerPlayer);
            if (newPlayer.deck == NULL)
            {
                printf("Erro ao criar jogador.\n");
                freeCountryList(&countryCards);
                playerListFree(playerList);
                return 1;
            }

            if (!playerListInsert(&playerList, newPlayer))
            {
                printf("Erro ao adicionar jogador à lista.\n");
                playerDestroy(&newPlayer);
                freeCountryList(&countryCards);
                playerListFree(playerList);
                return 1;
            }
        }
    }

    printf("Distribuindo cartas...\n");
    if (!distributeCards(countryCards, playerList))
    {
        printf("Erro ao distribuir cartas.\n");
        freeCountryList(&countryCards);
        playerListFree(playerList);
        return 1;
    }

    printf("\nCartas distribuídas com sucesso!\n");
    displayMainDeck(countryCards);
    displayAllPlayers(playerList);

    // Loop principal do jogo
    while (1)
    {
        PlayerNode *currentPlayer = playerList;
        while (currentPlayer != NULL)
        {
            printf("\n=== %s's Turn ===\n", currentPlayer->data.name);

            if (deckIsEmpty(currentPlayer->data.deck))
            {
                printf("%s has no cards left and is out of the game.\n", currentPlayer->data.name);
                eliminatePlayer(&playerList, currentPlayer);
                currentPlayer = currentPlayer->next;
                if (currentPlayer == NULL)
                {
                    currentPlayer = playerList;
                }
                continue;
            }

            turnGame(NULL, playerList);
            checkGameOver(playerList);

            currentPlayer = currentPlayer->next;
        }
    }

    printf("Liberando memória...\n");
    freeCountryList(&countryCards);
    playerListFree(playerList);

    printf("Programa finalizado.\n");
    return 0;
}