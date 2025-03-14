#ifndef UI_UTILS_H
#define UI_UTILS_H
#include <curses.h>
/**
 * @file ui_utils.h
 * @brief Coletânia de funções para facilitar o uso da biblioteca curses.
 */

/**
 * @brief Imprime um botão na tela principal
 * 
 * @param y Coordenada y do botão
 * @param x Coordenada x do botão
 * @param label Texto de exibição do botão
 * @param selected se o botão está selecionado
 */
void mvprintbutton(int y, int x, char *label, int selected);

/**
 * @brief Imprime um botão em uma janela do curses.
 * 
 * @param window Ponteiro para a janela
 * @param y Coordenada y do botão
 * @param x Coordenada x do botão
 * @param label Texto de exibição do botão
 * @param selected se o botão está selecionado
 */
void mvwprintbutton(WINDOW *window, int y, int x, char *label, int selected);

/**
 * @brief Imprime bordas em uma janela e botões.
 *
 * @param window Ponteiro para a janela
 * @param options Vetor de strings literais com as opções do menu
 * @param numOptions Número de elementos no vetor options
 * @param currOption Índice da opção selecionada no vetor options
 */
void wprintListMenu(WINDOW * window, char *options[], int numOptions, int currOption);
#endif
