#include <stdio.h>

#include "../include/card.h"
#include "../include/countries.h"

int main()
{
	Card *countries;

    printf("Allocated and initialized:\n");
	initialize_country_list(&countries);
    printf("********************\n");

    printf("Cards Value Sorted:\n");
    print_cards_value(countries);
    printf("********************\n");

    shuffle(countries, GLOBAL_COUNTRIES_AMOUNT);

    printf("Countries Unsorted:\n");
    print_cards_value(countries);
    printf("********************\n");

    printf("Free Deck:\n");
    free_country_list(&countries);

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
