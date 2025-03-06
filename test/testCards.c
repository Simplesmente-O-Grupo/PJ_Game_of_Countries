#include <stdio.h>
#include <stdlib.h>

#define TOTAL_CARDS 80

typedef struct Cards
{
    int card_id;            // card identification
    char card_name[30];     // card name of the country - Increase array size because of country name
    char card_category[30]; // card category, such as country's Continent
    int card_defence;       // defence card attribute
    int card_army;          // army card attribute
    int card_navy;          // navy card attribute
    int card_airforce;      // airforce card attribute
} Cards;

Cards *allocate_memory_cards()
{
    Cards *deck = (Cards *)malloc(TOTAL_CARDS * sizeof(Cards));
    if (deck == NULL)
    {
        printf("Error memory allocation!\n");
        exit(1);
    }
    return deck;
}
// Function to write each element of card
void initizalize_cards(Cards *deck)
{
    deck[0] = (Cards){1, "Brazil", "America", 0, 0, 0, 0};
    deck[1] = (Cards){2, "Germany", "Europe", 0, 0, 0, 0};
    deck[2] = (Cards){3, "China", "Asia", 0, 0, 0, 0};
    deck[3] = (Cards){4, "Australia", "Oceania", 0, 0, 0, 0};
    deck[4] = (Cards){5, "Canada", "America", 0, 0, 0, 0};
    deck[5] = (Cards){6, "India", "Asia", 0, 0, 0, 0};
    deck[6] = (Cards){7, "France", "Europe", 0, 0, 0, 0};
    deck[7] = (Cards){8, "Russia", "Asia", 0, 0, 0, 0};
    deck[8] = (Cards){9, "United Kingdom", "Europe", 0, 0, 0, 0};
    deck[9] = (Cards){10, "Japan", "Asia", 0, 0, 0, 0};

    deck[10] = (Cards){11, "South Africa", "Africa", 0, 0, 0, 0};
    deck[11] = (Cards){12, "Mexico", "America", 0, 0, 0, 0};
    deck[12] = (Cards){13, "Italy", "Europe", 0, 0, 0, 0};
    deck[13] = (Cards){14, "Argentina", "America", 0, 0, 0, 0};
    deck[14] = (Cards){15, "South Korea", "Asia", 0, 0, 0, 0};
    deck[15] = (Cards){16, "Nigeria", "Africa", 0, 0, 0, 0};
    deck[16] = (Cards){17, "Egypt", "Africa", 0, 0, 0, 0};
    deck[17] = (Cards){18, "Saudi Arabia", "Asia", 0, 0, 0, 0};
    deck[18] = (Cards){19, "Pakistan", "Asia", 0, 0, 0, 0};
    deck[19] = (Cards){20, "Indonesia", "Asia", 0, 0, 0, 0};

    deck[20] = (Cards){21, "Turkey", "Asia", 0, 0, 0, 0};
    deck[21] = (Cards){22, "Colombia", "America", 0, 0, 0, 0};
    deck[22] = (Cards){23, "Kenya", "Africa", 0, 0, 0, 0};
    deck[23] = (Cards){24, "Peru", "America", 0, 0, 0, 0};
    deck[24] = (Cards){25, "Thailand", "Asia", 0, 0, 0, 0};
    deck[25] = (Cards){26, "Poland", "Europe", 0, 0, 0, 0};
    deck[26] = (Cards){27, "Ukraine", "Europe", 0, 0, 0, 0};
    deck[27] = (Cards){28, "Iraq", "Asia", 0, 0, 0, 0};
    deck[28] = (Cards){29, "Algeria", "Africa", 0, 0, 0, 0};
    deck[29] = (Cards){30, "Venezuela", "America", 0, 0, 0, 0};

    deck[30] = (Cards){31, "Chile", "America", 0, 0, 0, 0};
    deck[31] = (Cards){32, "Morocco", "Africa", 0, 0, 0, 0};
    deck[32] = (Cards){33, "Czech Republic", "Europe", 0, 0, 0, 0};
    deck[33] = (Cards){34, "Angola", "Africa", 0, 0, 0, 0};
    deck[34] = (Cards){35, "Uzbekistan", "Asia", 0, 0, 0, 0};
    deck[35] = (Cards){36, "Malaysia", "Asia", 0, 0, 0, 0};
    deck[36] = (Cards){37, "Romania", "Europe", 0, 0, 0, 0};
    deck[37] = (Cards){38, "Kazakhstan", "Asia", 0, 0, 0, 0};
    deck[38] = (Cards){39, "Qatar", "Asia", 0, 0, 0, 0};
    deck[39] = (Cards){40, "Greece", "Europe", 0, 0, 0, 0};

    deck[40] = (Cards){41, "Ecuador", "America", 0, 0, 0, 0};
    deck[41] = (Cards){42, "Bulgaria", "Europe", 0, 0, 0, 0};
    deck[42] = (Cards){43, "Sri Lanka", "Asia", 0, 0, 0, 0};
    deck[43] = (Cards){44, "Tanzania", "Africa", 0, 0, 0, 0};
    deck[44] = (Cards){45, "Syria", "Asia", 0, 0, 0, 0};
    deck[45] = (Cards){46, "Zimbabwe", "Africa", 0, 0, 0, 0};
    deck[46] = (Cards){47, "Croatia", "Europe", 0, 0, 0, 0};
    deck[47] = (Cards){48, "Honduras", "America", 0, 0, 0, 0};
    deck[48] = (Cards){49, "Bosnia and Herzegovina", "Europe", 0, 0, 0, 0};
    deck[49] = (Cards){50, "Panama", "America", 0, 0, 0, 0};

    deck[50] = (Cards){51, "Senegal", "Africa", 0, 0, 0, 0};
    deck[51] = (Cards){52, "Iceland", "Europe", 0, 0, 0, 0};
    deck[52] = (Cards){53, "Belarus", "Europe", 0, 0, 0, 0};
    deck[53] = (Cards){54, "Guatemala", "America", 0, 0, 0, 0};
    deck[54] = (Cards){55, "Ethiopia", "Africa", 0, 0, 0, 0};
    deck[55] = (Cards){56, "Oman", "Asia", 0, 0, 0, 0};
    deck[56] = (Cards){57, "Bahrain", "Asia", 0, 0, 0, 0};
    deck[57] = (Cards){58, "Jordan", "Asia", 0, 0, 0, 0};
    deck[58] = (Cards){59, "Tunisia", "Africa", 0, 0, 0, 0};
    deck[59] = (Cards){60, "Kuwait", "Asia", 0, 0, 0, 0};

    deck[60] = (Cards){61, "Haiti", "America", 0, 0, 0, 0};
    deck[61] = (Cards){62, "Latvia", "Europe", 0, 0, 0, 0};
    deck[62] = (Cards){63, "Mali", "Africa", 0, 0, 0, 0};
    deck[63] = (Cards){64, "Nepal", "Asia", 0, 0, 0, 0};
    deck[64] = (Cards){65, "Armenia", "Asia", 0, 0, 0, 0};
    deck[65] = (Cards){66, "Mauritius", "Africa", 0, 0, 0, 0};
    deck[66] = (Cards){67, "Luxembourg", "Europe", 0, 0, 0, 0};
    deck[67] = (Cards){68, "Singapore", "Asia", 0, 0, 0, 0};
    deck[68] = (Cards){69, "Malta", "Europe", 0, 0, 0, 0};
    deck[69] = (Cards){70, "Cyprus", "Europe", 0, 0, 0, 0};

    deck[70] = (Cards){71, "Reunion", "Africa", 0, 0, 0, 0};
    deck[71] = (Cards){72, "Jordan", "Asia", 0, 0, 0, 0};
    deck[72] = (Cards){73, "Mauritania", "Africa", 0, 0, 0, 0};
    deck[73] = (Cards){74, "Gabon", "Africa", 0, 0, 0, 0};
    deck[74] = (Cards){75, "Monaco", "Europe", 0, 0, 0, 0};
    deck[75] = (Cards){76, "Liechtenstein", "Europe", 0, 0, 0, 0};
    deck[76] = (Cards){77, "Maldives", "Asia", 0, 0, 0, 0};
    deck[77] = (Cards){78, "Bhutan", "Asia", 0, 0, 0, 0};
    deck[78] = (Cards){79, "Fiji", "Oceania", 0, 0, 0, 0};
    deck[79] = (Cards){80, "USA", "America", 0, 0, 0, 0};
}

// Just test - This function will not implemented int the game
void print_cards_value(Cards *deck)
{
    for (int i = 0; i < TOTAL_CARDS; i++)
    {
        printf("Card ID: %d\n Country Name: %s\n Country Continent: %s\n Card defense: %d\n Card army: %d\n Card navy: %d\n Card airforce: %d\n",
               deck[i].card_id, deck[i].card_name,
               deck[i].card_category, deck[i].card_defence,
               deck[i].card_army, deck[i].card_navy, deck[i].card_airforce);

        printf("*************************************************\n ");
    }
}

void free_cards(Cards **deck) // Pass pointer to pointer to set it to NULL
{
    if (*deck != NULL)
    {
        free(*deck);
        *deck = NULL; // Set the pointer to NULL after freeing
        printf("Deck memory has been freed.\n");
    }
    else
    {
        printf("Deck is already freed.\n");
    }
}

int main()
{
    printf("Allocated:\n");
    Cards *deck = allocate_memory_cards();
    printf("********************\n");

    printf("Initialized deck:\n ");
    initizalize_cards(deck);
    printf("********************\n");

    printf("Cards Value:\n");
    print_cards_value(deck);
    printf("********************\n");

    printf("Free Deck:\n");
    free_cards(&deck);

    // Verify that the deck has been freed
    if (deck == NULL)
    {
        printf("DEck is successfully freed and set to NULL.\n");
    }
    else
    {
        printf("Deck is not freed.\n");
    }

    return 0;
}