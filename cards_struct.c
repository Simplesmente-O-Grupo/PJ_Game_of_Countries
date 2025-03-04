#ifndef CARDS_H
#define CARDS_H

// Requisite RF01 - struct to represent Body Cards

typedef struct Cards
{
    int card_id;            // card identification
    char card_name[15];     // card name of the country
    char card_category[15]; // card category, such as country's Continent
    int card_defence;       // defence card attribute
    int card_army;          // army card attribute
    int card_navy;          // navy card attribute
    int card_airforce;      // airforce card attribute
} Cards;

#endif