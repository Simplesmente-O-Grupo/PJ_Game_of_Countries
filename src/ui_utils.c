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

void createStrField(StrField *field, int width, int y, int x, char *label)
{
	field->window = newwin(3, width, y, x);
	keypad(field->window, TRUE);
	strcpy(field->label, label);
	field->labelLen = strlen(label);
	field->value[0] = '\0';
}

void drawStrField(StrField *field)
{
	werase(field->window);
	box(field->window, 0, 0);

	wmove(field->window, 1, 1);
	wprintw(field->window,  "%s: ", field->label);
	wprintw(field->window,  "%s", field->value);

	wrefresh(field->window);
}

void focusStrField(StrField *field) {
	drawStrField(field);
	/* Habilita o cursor do terminal */
	curs_set(1);
	/* Mostra o que o usuário digitou */
	echo();
	while (strlen(field->value) <= 0) {
		wmove(field->window, 1, 1 + strlen(field->label) + 2);
		wgetnstr(field->window, field->value, TEXT_FIELD_MAXLEN);
	}
	/* Esconte o input do usuário */
	noecho();
	/* Esconde o cursor do terminal */
	curs_set(0);
}

void createIntField(IntField *field, int width, int y, int x, char *label, int maxValue, int minValue)
{
	field->window = newwin(3, width, y, x);
	keypad(field->window, TRUE);
	strcpy(field->label, label);
	field->labelLen = strlen(label);
	field->value = minValue;
	field->maxValue = maxValue;
	field->minValue = minValue;
}

void drawIntField(IntField *field)
{
	werase(field->window);
	box(field->window, 0, 0);

	wmove(field->window, 1, 1);
	wprintw(field->window, "%s", field->label);
	wprintw(field->window, ": %d", field->value);

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
			if (field->value < field->minValue) field->value = field->minValue;
		} 
		/* Alternativamente, o usuário também pode incrementar
		* e decrementar o valor do campo com as setas do teclado
		*/
		else if (key == KEY_UP)
		{
			if (field->value >= field->maxValue) {
				field->value = field->minValue;
			} else {
				field->value++;
			}
		}
		else if (key == KEY_DOWN)
		{
			if (field->value <= field->minValue) {
				field->value = field->maxValue;
			} else {
				field->value--;
			}
		}
		/* O backspace remove o dígito menos significativo do número, similar à uma
		 * entrada de texto comum
		 */
		else if (key == KEY_BACKSPACE || key == '\b')
		{
			field->value = field->value / 10;
			if (field->value < field->minValue) field->value = field->minValue;
		}
		drawIntField(field);
		/* Este processo só para quando o usuário apertar Enter e confirmar sua escolha */
	} while (key != '\n');
}
