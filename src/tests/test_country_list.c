#include <stdio.h>

#include "../include/card.h"
#include "../include/countries.h"

int main()
{
	Card *countries;

    printf("Allocated and initialized:\n");
	initializeCountryList(&countries);
    printf("********************\n");

    printf("Cards Value Sorted:\n");
    printCardsValue(countries);
    printf("********************\n");

    shuffle(countries, GLOBAL_COUNTRIES_AMOUNT);

    printf("Countries Unsorted:\n");
    printCardsValue(countries);
    printf("********************\n");

    printf("Free Deck:\n");
    freeCountryList(&countries);

    // Verify that the deck has been freed
    if (countries == NULL)
    {
        printf("Deck is successfully freed and set to NULL.\n");
    }
    else
    {
        printf("Deck is not freed.\n");
    }

    return 0;
}
