#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/player.h"
#include "include/deck.h"
#include "include/card.h"
#include "include/player_list.h"
#include "include/countries.h"

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
void displayAllPlayers(PlayerNode *head)
{
    PlayerNode *current = head;
    do {
        displayPlayerDeck(current->data);
        current = current->next;
    } while (current != head);
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

CardAttribute promptAttribute(Card peekCard) {
	CardAttribute chosenAttribute;
	int scannedAttribute;
	printf("\nChoose an attribute to battle with:\n");
	printf("1) Airforce (%d)\n", peekCard.airforce);
	printf("2) Navy (%d)\n", peekCard.navy);
	printf("3) Defence (%d)\n", peekCard.defence);
	printf("4) Army (%d)\n", peekCard.army);

	if (scanf("%d", &scannedAttribute) != 1 || scannedAttribute < 1 || scannedAttribute > 4)
	{
		printf("Invalid choice. Defaulting to Airforce.\n");
		chosenAttribute = AIRFORCE;
	} else {
		switch(scannedAttribute) {
			case 1:
				chosenAttribute = AIRFORCE;
				break;
			case 2:
				chosenAttribute = NAVY;
				break;
			case 3:
				chosenAttribute = DEFENCE;
				break;
			case 4:
				chosenAttribute = ARMY;
				break;
		}
	}
	return chosenAttribute;
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

    while (getchar() != '\n');

    printf("Número de jogadores: %d\n", numPlayers);

    Card *countryCards = NULL;
    printf("Inicializando a lista de países...\n");
    initializeCountryList(&countryCards);
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
                while (getchar() != '\n');
            }

            for (int j = 0; playerName[j]; j++)
            {
                playerName[j] = toupper(playerName[j]);
            }

            printf("Criando jogador %s...\n", playerName);
            Player newPlayer = playerCreate(i + 1, playerName);

            playerListInsert(&playerList, newPlayer);
        }
    }

    printf("Distribuindo cartas...\n");
    distributeCards(countryCards, playerList);
	freeCountryList(&countryCards);

    printf("\nCartas distribuídas com sucesso!\n");
    displayAllPlayers(playerList);

	PlayerNode *turnMaster = playerList;
	Deck *battleDeck = deckInitialize(GLOBAL_COUNTRIES_AMOUNT);
	// Loop principal do jogo - enquanto houver mais de um jogador.
	do {
		PlayerNode *temp = playerList;

		/* 1 Show the player his card */
		printf("\n%s:\n", turnMaster->data.name);
		displayCard(deckPeek(turnMaster->data.deck));

		/* 2 Ask for an attribute */
		CardAttribute attr = promptAttribute(deckPeek(turnMaster->data.deck));
		/* 3 Find the player with the highest attribute. */
		PlayerNode *roundWinner = playerListHighestAttribute(playerList, attr);
		/* 4 Stash away everyone's cards. */
		do {
			if (deckGetHeight(temp->data.deck) > 0 && temp != turnMaster ) {
				deckPush(battleDeck, deckPop(temp->data.deck));
			}
			temp = temp->next;
		}while (temp != playerList);
		if (deckGetHeight(turnMaster->data.deck) > 0) {
			deckPush(battleDeck, deckPop(turnMaster->data.deck));
		}

		/* 5 If there's a tie, go back to step. 1 */
		if (roundWinner == NULL) continue;

		/* 6 If there's not, give all of the stashed cards to the winner player. */
		int cardsWon = deckGetHeight(battleDeck);
		while (deckGetHeight(battleDeck) > 0) {
			deckPush(roundWinner->data.deck, deckPop(battleDeck));
		}
		printf("%s Ganhou o round e tem %d cartas (%d cartas ganhas)\n", roundWinner->data.name, deckGetHeight(roundWinner->data.deck), cardsWon);
		

		temp = turnMaster;

		/* 7 Remove players with no cards */
		/* 7.1 Make sure the turn mater has some cards */
		while (deckGetHeight(turnMaster->data.deck) <= 0) {
			turnMaster = turnMaster->next;
		}

		/* 7.2 Remove players with no cards */
		temp = playerList;
		do {
			PlayerNode *next = temp->next;
			if (deckGetHeight(temp->data.deck) <= 0) {
				playerListRemove(&playerList, temp);
			}
			temp = next;
		} while(temp != playerList);

		/* 8 If the winner player is the turn master, go back to step 1. */
		if (roundWinner == turnMaster) continue;

		/* 9 Otherwise, go to the next player */
		turnMaster = turnMaster->next;
	} while (playerList->next != playerList);

	printf("\n%s WINS THE GAME with %d cards!\n", playerList->data.name, deckGetHeight(playerList->data.deck));
	printf("Liberando memória...\n");
	playerListFree(&playerList);

	printf("Programa finalizado.\n");
	return 0;
}
