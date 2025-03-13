#ifndef CARD_H
#define CARD_H

/**
 * @file card.h
 * @brief Este documento define uma estrutura de cartas para o jogo.
 */

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

/**
 * @brief Cria uma carta. Só é usada no início do jogo para popular o deck principal.
 *
 * @param id id da carta
 * @param name string com o nome do país
 * @param category continente do país
 * @param defence Valor de defesa do país
 * @param army Valor de exército do país
 * @param navy Valor de marinha do país
 * @param airforce Valor da força aérea do país
 * @return Uma estrutura de carta
*/
Card createCard(int id, char *name, char *category, int defence, int army, int navy, int airforce);

#endif
