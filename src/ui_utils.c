#include <curses.h>
#include <string.h>
#include <ctype.h>
#include "include/ui_utils.h"

void mvprintbutton(int y, int x, char *label, int selected) {
	if (selected)
		/* Ativa destaque de texto */
		attron(A_STANDOUT);
	mvprintw(y, x, "%s", label);
	/* Desativa destaque de texto */
	attroff(A_STANDOUT);
}
void mvwprintbutton(WINDOW *window, int y, int x, char *label, int selected) {
	if (selected)
		wattron(window, A_STANDOUT);
	mvwprintw(window, y, x, "%s", label);
	wattroff(window, A_STANDOUT);
}

void wprintListMenu(WINDOW * window, char *options[], int numOptions, int currOption) {
	int selected = 0;
	/* desenha uma borda padrão para a janela */
	box(window, 0, 0);
	for (int i = 0; i < numOptions; i++) {
		if (currOption == i)
			selected = 1;
		else
			selected = 0;
		mvwprintbutton(window, i+1, 1, options[i], selected);
	}
}

void createStrField(StrField *field, int height, int width, int y, int x, char *label)
{
	field->window = newwin(height, width, y, x);
	keypad(field->window, TRUE);
	strcpy(field->label, label);
	field->labelLen = strlen(label);
	field->value[0] = '\0';
}

void drawStrField(StrField *field)
{
	wclear(field->window);
	box(field->window, 0, 0);

	wmove(field->window, 1, 1);
	wprintw(field->window,  "%s", field->label);
	wprintw(field->window,  ": %s", field->value);

	wrefresh(field->window);
}

void focusStrField(StrField *field) {
	int key;
	/* Guarda o índice do final do valor do campo de texto */
	int valueEnd = 0;

	/* Posiciona a variável no final do texto */
	while (field->value[valueEnd] != '\0' && valueEnd < 50 - 1)
	{
		valueEnd++;
	}

	drawStrField(field);
	do {
		key = wgetch(field->window);
		/* a entrada permite somente letras, números e espaços */
		if ((isalnum(key) || isspace(key)) && valueEnd < 50 - 1)
		{
			field->value[valueEnd++] = key;
			field->value[valueEnd] = '\0';
		} 
		/* apaca um caractere do valor do campo. */
		else if (key == KEY_BACKSPACE && valueEnd > 0)
		{
			field->value[--valueEnd] = '\0';
		}
		drawStrField(field);
	} while (key != '\n');
}
void createIntField(IntField *field, int height, int width, int y, int x, char *label, int maxValue)
{
	field->window = newwin(height, width, y, x);
	keypad(field->window, TRUE);
	strcpy(field->label, label);
	field->labelLen = strlen(label);
	field->value = 0;
	field->maxValue = maxValue;
}

void drawIntField(IntField *field)
{
	wclear(field->window);
	box(field->window, 0, 0);

	wmove(field->window, 1, 1);
	wprintw(field->window,  "%s", field->label);
	wprintw(field->window,  ": %d", field->value);

	wrefresh(field->window);
}

void focusIntField(IntField *field) {
	int key;

	drawIntField(field);
	do {
		key = wgetch(field->window);
		/* Simula uma entrada de texto, onde um número é
		* preenchido da direita para a esquerda
		*/
		if (isdigit(key))
		{
			field->value = (field->value * 10) + (key - '0');
			if (field->value > field->maxValue) field->value = field->maxValue;
		} 
		/* Alternativamente, o usuário também pode incrementar
		* e decrementar o valor do campo com as setas do teclado
		*/
		else if (key == KEY_UP)
		{
			/* esta conta garante que o incremento nunca será maior que o valor máximo. */
			field->value = (field->value + 1) % (field->maxValue + 1);
		}
		else if (key == KEY_DOWN)
		{
			/* esta conta garante que o decremento nunca será menor que 0 */
			field->value = (field->maxValue + field->value) % (field->maxValue + 1);
		}
		/* O backspace remove o dígito menos significativo do número, similar à uma
		 * entrada de texto comum
		 */
		else if (key == KEY_BACKSPACE)
		{
			field->value = field->value / 10;
		}
		drawIntField(field);
		/* Este processo só para quando o usuário apertar Enter e confirmar sua escolha */
	} while (key != '\n');
}
