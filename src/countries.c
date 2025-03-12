#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "include/countries.h"
#include "include/card.h"

int initializeCountryList(Card **cards) {
	*cards = malloc(sizeof(Card) * GLOBAL_COUNTRIES_AMOUNT);
	if (*cards == NULL) {
		fprintf(stderr, "[ERR]: Falha ao criar cartas.\n");
		return 0;
	}

	(*cards)[0] = createCard(1, "Brazil", "America", 0, 0, 0, 0);
	(*cards)[1] = createCard(2, "Germany", "Europe", 0, 0, 0, 0);
	(*cards)[2] = createCard(3, "China", "Asia", 0, 0, 0, 0);
	(*cards)[3] = createCard(4, "Australia", "Oceania", 0, 0, 0, 0);
	(*cards)[4] = createCard(5, "Canada", "America", 0, 0, 0, 0);
	(*cards)[5] = createCard(6, "India", "Asia", 0, 0, 0, 0);
	(*cards)[6] = createCard(7, "France", "Europe", 0, 0, 0, 0);
	(*cards)[7] = createCard(8, "Russia", "Asia", 0, 0, 0, 0);
	(*cards)[8] = createCard(9, "United Kingdom", "Europe", 0, 0, 0, 0);
	(*cards)[9] = createCard(10, "Japan", "Asia", 0, 0, 0, 0);

	(*cards)[10] = createCard(11, "South Africa", "Africa", 0, 0, 0, 0);
	(*cards)[11] = createCard(12, "Mexico", "America", 0, 0, 0, 0);
	(*cards)[12] = createCard(13, "Italy", "Europe", 0, 0, 0, 0);
	(*cards)[13] = createCard(14, "Argentina", "America", 0, 0, 0, 0);
	(*cards)[14] = createCard(15, "South Korea", "Asia", 0, 0, 0, 0);
	(*cards)[15] = createCard(16, "Nigeria", "Africa", 0, 0, 0, 0);
	(*cards)[16] = createCard(17, "Egypt", "Africa", 0, 0, 0, 0);
	(*cards)[17] = createCard(18, "Saudi Arabia", "Asia", 0, 0, 0, 0);
	(*cards)[18] = createCard(19, "Pakistan", "Asia", 0, 0, 0, 0);
	(*cards)[19] = createCard(20, "Indonesia", "Asia", 0, 0, 0, 0);

	(*cards)[20] = createCard(21, "Turkey", "Asia", 0, 0, 0, 0);
	(*cards)[21] = createCard(22, "Colombia", "America", 0, 0, 0, 0);
	(*cards)[22] = createCard(23, "Kenya", "Africa", 0, 0, 0, 0);
	(*cards)[23] = createCard(24, "Peru", "America", 0, 0, 0, 0);
	(*cards)[24] = createCard(25, "Thailand", "Asia", 0, 0, 0, 0);
	(*cards)[25] = createCard(26, "Poland", "Europe", 0, 0, 0, 0);
	(*cards)[26] = createCard(27, "Ukraine", "Europe", 0, 0, 0, 0);
	(*cards)[27] = createCard(28, "Iraq", "Asia", 0, 0, 0, 0);
	(*cards)[28] = createCard(29, "Algeria", "Africa", 0, 0, 0, 0);
	(*cards)[29] = createCard(30, "Venezuela", "America", 0, 0, 0, 0);

	(*cards)[30] = createCard(31, "Chile", "America", 0, 0, 0, 0);
	(*cards)[31] = createCard(32, "Morocco", "Africa", 0, 0, 0, 0);
	(*cards)[32] = createCard(33, "Czech Republic", "Europe", 0, 0, 0, 0);
	(*cards)[33] = createCard(34, "Angola", "Africa", 0, 0, 0, 0);
	(*cards)[34] = createCard(35, "Uzbekistan", "Asia", 0, 0, 0, 0);
	(*cards)[35] = createCard(36, "Malaysia", "Asia", 0, 0, 0, 0);
	(*cards)[36] = createCard(37, "Romania", "Europe", 0, 0, 0, 0);
	(*cards)[37] = createCard(38, "Kazakhstan", "Asia", 0, 0, 0, 0);
	(*cards)[38] = createCard(39, "Qatar", "Asia", 0, 0, 0, 0);
	(*cards)[39] = createCard(40, "Greece", "Europe", 0, 0, 0, 0);

	(*cards)[40] = createCard(41, "Ecuador", "America", 0, 0, 0, 0);
	(*cards)[41] = createCard(42, "Bulgaria", "Europe", 0, 0, 0, 0);
	(*cards)[42] = createCard(43, "Sri Lanka", "Asia", 0, 0, 0, 0);
	(*cards)[43] = createCard(44, "Tanzania", "Africa", 0, 0, 0, 0);
	(*cards)[44] = createCard(45, "Syria", "Asia", 0, 0, 0, 0);
	(*cards)[45] = createCard(46, "Zimbabwe", "Africa", 0, 0, 0, 0);
	(*cards)[46] = createCard(47, "Croatia", "Europe", 0, 0, 0, 0);
	(*cards)[47] = createCard(48, "Honduras", "America", 0, 0, 0, 0);
	(*cards)[48] = createCard(49, "Bosnia and Herzegovina", "Europe", 0, 0, 0, 0);
	(*cards)[49] = createCard(50, "Panama", "America", 0, 0, 0, 0);

	(*cards)[50] = createCard(51, "Senegal", "Africa", 0, 0, 0, 0);
	(*cards)[51] = createCard(52, "Iceland", "Europe", 0, 0, 0, 0);
	(*cards)[52] = createCard(53, "Belarus", "Europe", 0, 0, 0, 0);
	(*cards)[53] = createCard(54, "Guatemala", "America", 0, 0, 0, 0);
	(*cards)[54] = createCard(55, "Ethiopia", "Africa", 0, 0, 0, 0);
	(*cards)[55] = createCard(56, "Oman", "Asia", 0, 0, 0, 0);
	(*cards)[56] = createCard(57, "Bahrain", "Asia", 0, 0, 0, 0);
	(*cards)[57] = createCard(58, "Jordan", "Asia", 0, 0, 0, 0);
	(*cards)[58] = createCard(59, "Tunisia", "Africa", 0, 0, 0, 0);
	(*cards)[59] = createCard(60, "Kuwait", "Asia", 0, 0, 0, 0);

	(*cards)[60] = createCard(61, "Haiti", "America", 0, 0, 0, 0);
	(*cards)[61] = createCard(62, "Latvia", "Europe", 0, 0, 0, 0);
	(*cards)[62] = createCard(63, "Mali", "Africa", 0, 0, 0, 0);
	(*cards)[63] = createCard(64, "Nepal", "Asia", 0, 0, 0, 0);
	(*cards)[64] = createCard(65, "Armenia", "Asia", 0, 0, 0, 0);
	(*cards)[65] = createCard(66, "Mauritius", "Africa", 0, 0, 0, 0);
	(*cards)[66] = createCard(67, "Luxembourg", "Europe", 0, 0, 0, 0);
	(*cards)[67] = createCard(68, "Singapore", "Asia", 0, 0, 0, 0);
	(*cards)[68] = createCard(69, "Malta", "Europe", 0, 0, 0, 0);
	(*cards)[69] = createCard(70, "Cyprus", "Europe", 0, 0, 0, 0);

	(*cards)[70] = createCard(71, "Reunion", "Africa", 0, 0, 0, 0);
	(*cards)[71] = createCard(72, "Jordan", "Asia", 0, 0, 0, 0);
	(*cards)[72] = createCard(73, "Mauritania", "Africa", 0, 0, 0, 0);
	(*cards)[73] = createCard(74, "Gabon", "Africa", 0, 0, 0, 0);
	(*cards)[74] = createCard(75, "Monaco", "Europe", 0, 0, 0, 0);
	(*cards)[75] = createCard(76, "Liechtenstein", "Europe", 0, 0, 0, 0);
	(*cards)[76] = createCard(77, "Maldives", "Asia", 0, 0, 0, 0);
	(*cards)[77] = createCard(78, "Bhutan", "Asia", 0, 0, 0, 0);
	(*cards)[78] = createCard(79, "Fiji", "Oceania", 0, 0, 0, 0);
	(*cards)[79] = createCard(80, "USA", "America", 0, 0, 0, 0);

	return 1;
}

// Just test - This function will not implemented int the game
void printCardsValue(Card *cards) {
	for (int i = 0; i < GLOBAL_COUNTRIES_AMOUNT; i++) {
		printf("Card ID: %d\n Country Name: %s\n Country Continent: %s\n Card defense: %d\n Card army: %d\n Card navy: %d\n Card airforce: %d\n",
		 cards[i].id, cards[i].name,
		 cards[i].category, cards[i].defence,
		 cards[i].army, cards[i].navy, cards[i].airforce);

		printf("*************************************************\n");
	}
}

void shuffle(Card *cards, int size) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Gera um índice aleatório entre 0 e 1

        // Replace cards[i] with cards[j]
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Pass pointer to pointer to set it to NULL
void freeCountryList(Card **cards) {
    if (*cards != NULL) {
        free(*cards);
        *cards = NULL; // Set the pointer to NULL after freeing
    }
}
