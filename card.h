#ifndef CARD_H
#define CARD_H

// Requisite RF01 - struct to represent Body Cards

#define CARD_MAX_NAME_LEN 30
#define CARD_MAX_CATEGORY_LEN 30
typedef struct Card {
    int id;            // card identification
    char name[CARD_MAX_NAME_LEN];     // card name of the country
    char category[CARD_MAX_CATEGORY_LEN]; // card category, such as country's Continent
    int defence;       // defence card attribute
    int army;          // army card attribute
    int navy;          // navy card attribute
    int airforce;      // airforce card attribute
} Card;

#endif
