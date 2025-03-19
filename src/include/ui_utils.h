#ifndef UI_UTILS_H
#define UI_UTILS_H
#include <curses.h>
/**
 * @file ui_utils.h
 * @brief Coletânia de funções para facilitar o uso da biblioteca curses.
 */

#define LABEL_MAXLEN 50
#define TEXT_FIELD_MAXLEN 50
/**
 * @brief Abstração de um campo de formulário para pedir um número inteiro ao usuário.
 */
typedef struct IntField {
	/**
	 * Janela do curses para exibição do campo
	 */
	WINDOW *window;
	/**
	 * Tamanho do texto de pergunta
	 */
	int labelLen;
	/**
	 * Texto de pergunta, impresso junto com o campo
	 */
	char label[LABEL_MAXLEN];
	/**
	 * Número fornecido pelo usuário
	 */
	int value;
	/**
	 * Valor máximo permitido pelo campo
	 */
	int maxValue;
} IntField;

/**
 * @brief Abstração de um campo de formulário para pedir texto ao usuário.
 */
typedef struct StrField {
	/**
	 * Janela do curses para exibição do campo
	 */
	WINDOW *window;
	/**
	 * Tamanho do texto de pergunta
	 */
	int labelLen;
	/**
	 * Texto de pergunta, impresso junto com o campo
	 */
	char label[50];
	/**
	 * Texto fornecido pelo usuário
	 */
	char value[50];
} StrField;


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

/**
 * @brief Cria um campo de texto para a interface.
 *
 * @param field Ponteiro para o campo em questão
 * @param height Altura da janela do campo
 * @param width Largura da janela do campo
 * @param y Coordenada y do campo
 * @param x Coordenada x do campo
 * @param label Texto para ser exibido ao usuário
 */
void createStrField(StrField *field, int height, int width, int y, int x, char *label);

/**
 * @brief desenha a janela de um campo de texto na tela
 * @param field Ponteiro para o campo em questão
 */
void drawStrField(StrField *field);

/**
 * @brief Toma controle da execução, desenha o campo e pede para o usuário digitar um texto.
 * @param field Ponteiro para o campo em questão
 */
void focusStrField(StrField *field);

/**
 * @brief Cria um campo de inteiro para a interface.
 *
 * @param field Ponteiro para o campo em questão
 * @param height Altura da janela do campo
 * @param width Largura da janela do campo
 * @param y Coordenada y do campo
 * @param x Coordenada x do campo
 * @param label Texto para ser exibido ao usuário
 * @param maxValue Valor máximo permitido pelo campo
 */
void createIntField(IntField *field, int height, int width, int y, int x, char *label, int maxValue);

/**
 * @brief desenha a janela de um campo de texto na tela.
 * @param field Ponteiro para o campo em questão
 */
void drawIntField(IntField *field);

/**
 * @brief Toma controle da execução, desenha o campo e pede para o usuário digitar um número.
 * @param field Ponteiro para o campo em questão
 */
void focusIntField(IntField *field);

#endif
