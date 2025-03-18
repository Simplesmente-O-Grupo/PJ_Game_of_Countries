#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "include/countries.h"
#include "include/player_list.h"
#include "include/card.h"

int initializeCountryList(Card **cards)
{
	*cards = malloc(sizeof(Card) * GLOBAL_COUNTRIES_AMOUNT);
	if (*cards == NULL)
	{
		fprintf(stderr, "[ERR]: Falha ao criar cartas.\n");
		return 0;
	}

	(*cards)[0] = createCard(1, "Brazil", "America", 85, 76, 92, 81);
	(*cards)[1] = createCard(2, "Germany", "Europe", 90, 95, 87, 88);
	(*cards)[2] = createCard(3, "China", "Asia", 94, 85, 78, 93);
	(*cards)[3] = createCard(4, "Australia", "Oceania", 87, 82, 79, 85);
	(*cards)[4] = createCard(5, "Canada", "America", 89, 91, 84, 86);
	(*cards)[5] = createCard(6, "India", "Asia", 86, 79, 84, 90);
	(*cards)[6] = createCard(7, "France", "Europe", 88, 93, 85, 84);
	(*cards)[7] = createCard(8, "Russia", "Asia", 92, 88, 82, 89);
	(*cards)[8] = createCard(9, "United Kingdom", "Europe", 86, 90, 84, 85);
	(*cards)[9] = createCard(10, "Japan", "Asia", 91, 94, 86, 88);

	(*cards)[10] = createCard(11, "South Africa", "Africa", 79, 76, 83, 78);
	(*cards)[11] = createCard(12, "Mexico", "America", 82, 78, 85, 81);
	(*cards)[12] = createCard(13, "Italy", "Europe", 87, 89, 91, 84);
	(*cards)[13] = createCard(14, "Argentina", "America", 84, 80, 93, 82);
	(*cards)[14] = createCard(15, "South Korea", "Asia", 88, 92, 83, 87);
	(*cards)[15] = createCard(16, "Nigeria", "Africa", 77, 72, 87, 79);
	(*cards)[16] = createCard(17, "Egypt", "Africa", 80, 76, 84, 81);
	(*cards)[17] = createCard(18, "Saudi Arabia", "Asia", 83, 85, 77, 84);
	(*cards)[18] = createCard(19, "Pakistan", "Asia", 79, 74, 80, 82);
	(*cards)[19] = createCard(20, "Indonesia", "Asia", 82, 79, 83, 85);

	(*cards)[20] = createCard(21, "Turkey", "Asia", 83, 81, 85, 82);
	(*cards)[21] = createCard(22, "Colombia", "America", 81, 78, 89, 80);
	(*cards)[22] = createCard(23, "Kenya", "Africa", 75, 71, 93, 76);
	(*cards)[23] = createCard(24, "Peru", "America", 79, 75, 87, 78);
	(*cards)[24] = createCard(25, "Thailand", "Asia", 82, 80, 84, 85);
	(*cards)[25] = createCard(26, "Poland", "Europe", 84, 87, 81, 83);
	(*cards)[26] = createCard(27, "Ukraine", "Europe", 83, 85, 79, 82);
	(*cards)[27] = createCard(28, "Iraq", "Asia", 77, 74, 80, 81);
	(*cards)[28] = createCard(29, "Algeria", "Africa", 78, 75, 83, 79);
	(*cards)[29] = createCard(30, "Venezuela", "America", 80, 76, 86, 78);

	(*cards)[30] = createCard(31, "Chile", "America", 82, 79, 85, 80);
	(*cards)[31] = createCard(32, "Morocco", "Africa", 77, 74, 81, 78);
	(*cards)[32] = createCard(33, "Czech Republic", "Europe", 84, 86, 80, 83);
	(*cards)[33] = createCard(34, "Angola", "Africa", 74, 70, 82, 75);
	(*cards)[34] = createCard(35, "Uzbekistan", "Asia", 78, 76, 81, 79);
	(*cards)[35] = createCard(36, "Malaysia", "Asia", 81, 79, 83, 82);
	(*cards)[36] = createCard(37, "Romania", "Europe", 81, 84, 79, 82);
	(*cards)[37] = createCard(38, "Kazakhstan", "Asia", 79, 77, 80, 81);
	(*cards)[38] = createCard(39, "Qatar", "Asia", 84, 87, 78, 85);
	(*cards)[39] = createCard(40, "Greece", "Europe", 83, 85, 82, 81);

	(*cards)[40] = createCard(41, "Ecuador", "America", 78, 75, 84, 77);
	(*cards)[41] = createCard(42, "Bulgaria", "Europe", 80, 83, 78, 81);
	(*cards)[42] = createCard(43, "Sri Lanka", "Asia", 77, 74, 79, 80);
	(*cards)[43] = createCard(44, "Tanzania", "Africa", 73, 69, 81, 74);
	(*cards)[44] = createCard(45, "Syria", "Asia", 76, 72, 79, 78);
	(*cards)[45] = createCard(46, "Zimbabwe", "Africa", 72, 68, 80, 73);
	(*cards)[46] = createCard(47, "Croatia", "Europe", 82, 84, 80, 83);
	(*cards)[47] = createCard(48, "Honduras", "America", 75, 72, 82, 76);
	(*cards)[48] = createCard(49, "Bosnia and Herzegovina", "Europe", 79, 81, 77, 80);
	(*cards)[49] = createCard(50, "Panama", "America", 76, 73, 81, 77);

	(*cards)[50] = createCard(51, "Senegal", "Africa", 75, 71, 83, 76);
	(*cards)[51] = createCard(52, "Iceland", "Europe", 85, 87, 83, 86);
	(*cards)[52] = createCard(53, "Belarus", "Europe", 81, 83, 78, 82);
	(*cards)[53] = createCard(54, "Guatemala", "America", 74, 71, 80, 75);
	(*cards)[54] = createCard(55, "Ethiopia", "Africa", 71, 67, 88, 72);
	(*cards)[55] = createCard(56, "Oman", "Asia", 80, 78, 76, 81);
	(*cards)[56] = createCard(57, "Bahrain", "Asia", 82, 80, 75, 83);
	(*cards)[57] = createCard(58, "Myanmar", "Asia", 79, 76, 78, 80);
	(*cards)[58] = createCard(59, "Tunisia", "Africa", 76, 73, 80, 77);
	(*cards)[59] = createCard(60, "Kuwait", "Asia", 83, 81, 74, 84);

	(*cards)[60] = createCard(61, "Haiti", "America", 69, 65, 78, 70);
	(*cards)[61] = createCard(62, "Latvia", "Europe", 80, 82, 77, 81);
	(*cards)[62] = createCard(63, "Mali", "Africa", 72, 68, 79, 73);
	(*cards)[63] = createCard(64, "Nepal", "Asia", 75, 72, 80, 76);
	(*cards)[64] = createCard(65, "Armenia", "Asia", 78, 75, 77, 79);
	(*cards)[65] = createCard(66, "Mauritius", "Africa", 77, 74, 76, 78);
	(*cards)[66] = createCard(67, "Luxembourg", "Europe", 87, 89, 84, 88);
	(*cards)[67] = createCard(68, "Singapore", "Asia", 89, 91, 82, 90);
	(*cards)[68] = createCard(69, "Malta", "Europe", 83, 85, 80, 84);
	(*cards)[69] = createCard(70, "Cyprus", "Europe", 82, 84, 79, 83);

	(*cards)[70] = createCard(71, "Reunion", "Africa", 76, 73, 75, 77);
	(*cards)[71] = createCard(72, "Jordan", "Asia", 79, 76, 78, 80); // Note: Jordan appears twice in your original list
	(*cards)[72] = createCard(73, "Mauritania", "Africa", 71, 67, 76, 72);
	(*cards)[73] = createCard(74, "Gabon", "Africa", 74, 70, 77, 75);
	(*cards)[74] = createCard(75, "Monaco", "Europe", 88, 90, 85, 89);
	(*cards)[75] = createCard(76, "Liechtenstein", "Europe", 86, 88, 84, 87);
	(*cards)[76] = createCard(77, "Maldives", "Asia", 81, 78, 76, 82);
	(*cards)[77] = createCard(78, "Bhutan", "Asia", 77, 74, 79, 78);
	(*cards)[78] = createCard(79, "Fiji", "Oceania", 79, 76, 81, 78);
	(*cards)[79] = createCard(80, "USA", "America", 93, 94, 91, 92);

	return 1;
}

// Just test - This function will not implemented int the game
void printCardsValue(Card *cards)
{
	for (int i = 0; i < GLOBAL_COUNTRIES_AMOUNT; i++)
	{
		printf("Card ID: %d\n Country Name: %s\n Country Continent: %s\n Card defense: %d\n Card army: %d\n Card navy: %d\n Card airforce: %d\n",
			   cards[i].id, cards[i].name,
			   cards[i].category, cards[i].defence,
			   cards[i].army, cards[i].navy, cards[i].airforce);

		printf("*************************************************\n");
	}
}

void shuffle(Card *cards, int size)
{
	srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

	for (int i = size - 1; i > 0; i--)
	{
		int j = rand() % (i + 1); // Gera um índice aleatório entre 0 e 1

		// Replace cards[i] with cards[j]
		Card temp = cards[i];
		cards[i] = cards[j];
		cards[j] = temp;
	}
}

// Pass pointer to pointer to set it to NULL
void freeCountryList(Card **cards)
{
	if (*cards != NULL)
	{
		free(*cards);
		*cards = NULL; // Set the pointer to NULL after freeing
	}
}

int distributeCards(Card *cards, PlayerNode *players)
{
	int cardsPerPlayer = GLOBAL_COUNTRIES_AMOUNT / playerListLen(players);
	int acc = 0;

    for (int i = 0; i < cardsPerPlayer; i++)
    {
		for (PlayerNode *current = players; current != NULL; current = current->next)
        {
            if (acc >= GLOBAL_COUNTRIES_AMOUNT) break;

			if (!deckPush(current->data.deck, cards[acc++]))
			{
				printf("Error: Failed to push card to player's deck\n");
				return 0;
			}
		}
    }

    return 1;
}
