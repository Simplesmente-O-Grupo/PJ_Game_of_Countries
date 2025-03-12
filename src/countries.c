#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "include/countries.h"
#include "include/card.h"

int initialize_country_list(Card **cards) {
	*cards = malloc(sizeof(Card) * GLOBAL_COUNTRIES_AMOUNT);
	if (*cards == NULL) {
		fprintf(stderr, "[ERR]: Falha ao criar cartas.\n");
		return 0;
	}

	(*cards)[0] = create_card(1, "Brazil", "America", 0, 0, 0, 0);
	(*cards)[1] = create_card(2, "Germany", "Europe", 0, 0, 0, 0);
	(*cards)[2] = create_card(3, "China", "Asia", 0, 0, 0, 0);
	(*cards)[3] = create_card(4, "Australia", "Oceania", 0, 0, 0, 0);
	(*cards)[4] = create_card(5, "Canada", "America", 0, 0, 0, 0);
	(*cards)[5] = create_card(6, "India", "Asia", 0, 0, 0, 0);
	(*cards)[6] = create_card(7, "France", "Europe", 0, 0, 0, 0);
	(*cards)[7] = create_card(8, "Russia", "Asia", 0, 0, 0, 0);
	(*cards)[8] = create_card(9, "United Kingdom", "Europe", 0, 0, 0, 0);
	(*cards)[9] = create_card(10, "Japan", "Asia", 0, 0, 0, 0);

	(*cards)[10] = create_card(11, "South Africa", "Africa", 0, 0, 0, 0);
	(*cards)[11] = create_card(12, "Mexico", "America", 0, 0, 0, 0);
	(*cards)[12] = create_card(13, "Italy", "Europe", 0, 0, 0, 0);
	(*cards)[13] = create_card(14, "Argentina", "America", 0, 0, 0, 0);
	(*cards)[14] = create_card(15, "South Korea", "Asia", 0, 0, 0, 0);
	(*cards)[15] = create_card(16, "Nigeria", "Africa", 0, 0, 0, 0);
	(*cards)[16] = create_card(17, "Egypt", "Africa", 0, 0, 0, 0);
	(*cards)[17] = create_card(18, "Saudi Arabia", "Asia", 0, 0, 0, 0);
	(*cards)[18] = create_card(19, "Pakistan", "Asia", 0, 0, 0, 0);
	(*cards)[19] = create_card(20, "Indonesia", "Asia", 0, 0, 0, 0);

	(*cards)[20] = create_card(21, "Turkey", "Asia", 0, 0, 0, 0);
	(*cards)[21] = create_card(22, "Colombia", "America", 0, 0, 0, 0);
	(*cards)[22] = create_card(23, "Kenya", "Africa", 0, 0, 0, 0);
	(*cards)[23] = create_card(24, "Peru", "America", 0, 0, 0, 0);
	(*cards)[24] = create_card(25, "Thailand", "Asia", 0, 0, 0, 0);
	(*cards)[25] = create_card(26, "Poland", "Europe", 0, 0, 0, 0);
	(*cards)[26] = create_card(27, "Ukraine", "Europe", 0, 0, 0, 0);
	(*cards)[27] = create_card(28, "Iraq", "Asia", 0, 0, 0, 0);
	(*cards)[28] = create_card(29, "Algeria", "Africa", 0, 0, 0, 0);
	(*cards)[29] = create_card(30, "Venezuela", "America", 0, 0, 0, 0);

	(*cards)[30] = create_card(31, "Chile", "America", 0, 0, 0, 0);
	(*cards)[31] = create_card(32, "Morocco", "Africa", 0, 0, 0, 0);
	(*cards)[32] = create_card(33, "Czech Republic", "Europe", 0, 0, 0, 0);
	(*cards)[33] = create_card(34, "Angola", "Africa", 0, 0, 0, 0);
	(*cards)[34] = create_card(35, "Uzbekistan", "Asia", 0, 0, 0, 0);
	(*cards)[35] = create_card(36, "Malaysia", "Asia", 0, 0, 0, 0);
	(*cards)[36] = create_card(37, "Romania", "Europe", 0, 0, 0, 0);
	(*cards)[37] = create_card(38, "Kazakhstan", "Asia", 0, 0, 0, 0);
	(*cards)[38] = create_card(39, "Qatar", "Asia", 0, 0, 0, 0);
	(*cards)[39] = create_card(40, "Greece", "Europe", 0, 0, 0, 0);

	(*cards)[40] = create_card(41, "Ecuador", "America", 0, 0, 0, 0);
	(*cards)[41] = create_card(42, "Bulgaria", "Europe", 0, 0, 0, 0);
	(*cards)[42] = create_card(43, "Sri Lanka", "Asia", 0, 0, 0, 0);
	(*cards)[43] = create_card(44, "Tanzania", "Africa", 0, 0, 0, 0);
	(*cards)[44] = create_card(45, "Syria", "Asia", 0, 0, 0, 0);
	(*cards)[45] = create_card(46, "Zimbabwe", "Africa", 0, 0, 0, 0);
	(*cards)[46] = create_card(47, "Croatia", "Europe", 0, 0, 0, 0);
	(*cards)[47] = create_card(48, "Honduras", "America", 0, 0, 0, 0);
	(*cards)[48] = create_card(49, "Bosnia and Herzegovina", "Europe", 0, 0, 0, 0);
	(*cards)[49] = create_card(50, "Panama", "America", 0, 0, 0, 0);

	(*cards)[50] = create_card(51, "Senegal", "Africa", 0, 0, 0, 0);
	(*cards)[51] = create_card(52, "Iceland", "Europe", 0, 0, 0, 0);
	(*cards)[52] = create_card(53, "Belarus", "Europe", 0, 0, 0, 0);
	(*cards)[53] = create_card(54, "Guatemala", "America", 0, 0, 0, 0);
	(*cards)[54] = create_card(55, "Ethiopia", "Africa", 0, 0, 0, 0);
	(*cards)[55] = create_card(56, "Oman", "Asia", 0, 0, 0, 0);
	(*cards)[56] = create_card(57, "Bahrain", "Asia", 0, 0, 0, 0);
	(*cards)[57] = create_card(58, "Jordan", "Asia", 0, 0, 0, 0);
	(*cards)[58] = create_card(59, "Tunisia", "Africa", 0, 0, 0, 0);
	(*cards)[59] = create_card(60, "Kuwait", "Asia", 0, 0, 0, 0);

	(*cards)[60] = create_card(61, "Haiti", "America", 0, 0, 0, 0);
	(*cards)[61] = create_card(62, "Latvia", "Europe", 0, 0, 0, 0);
	(*cards)[62] = create_card(63, "Mali", "Africa", 0, 0, 0, 0);
	(*cards)[63] = create_card(64, "Nepal", "Asia", 0, 0, 0, 0);
	(*cards)[64] = create_card(65, "Armenia", "Asia", 0, 0, 0, 0);
	(*cards)[65] = create_card(66, "Mauritius", "Africa", 0, 0, 0, 0);
	(*cards)[66] = create_card(67, "Luxembourg", "Europe", 0, 0, 0, 0);
	(*cards)[67] = create_card(68, "Singapore", "Asia", 0, 0, 0, 0);
	(*cards)[68] = create_card(69, "Malta", "Europe", 0, 0, 0, 0);
	(*cards)[69] = create_card(70, "Cyprus", "Europe", 0, 0, 0, 0);

	(*cards)[70] = create_card(71, "Reunion", "Africa", 0, 0, 0, 0);
	(*cards)[71] = create_card(72, "Jordan", "Asia", 0, 0, 0, 0);
	(*cards)[72] = create_card(73, "Mauritania", "Africa", 0, 0, 0, 0);
	(*cards)[73] = create_card(74, "Gabon", "Africa", 0, 0, 0, 0);
	(*cards)[74] = create_card(75, "Monaco", "Europe", 0, 0, 0, 0);
	(*cards)[75] = create_card(76, "Liechtenstein", "Europe", 0, 0, 0, 0);
	(*cards)[76] = create_card(77, "Maldives", "Asia", 0, 0, 0, 0);
	(*cards)[77] = create_card(78, "Bhutan", "Asia", 0, 0, 0, 0);
	(*cards)[78] = create_card(79, "Fiji", "Oceania", 0, 0, 0, 0);
	(*cards)[79] = create_card(80, "USA", "America", 0, 0, 0, 0);

	return 1;
}

// Just test - This function will not implemented int the game
void print_cards_value(Card *cards) {
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
void free_country_list(Card **cards) {
    if (*cards != NULL) {
        free(*cards);
        *cards = NULL; // Set the pointer to NULL after freeing
    }
}
