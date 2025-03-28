#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/card.h"

/*
► Função para criar uma carta.
► Retornando uma struct to tipo card.
► Objeto card é criado com valores passados como argumento.
*/

Card createCard(int id, char *name, char *category, int defence, int army, int navy, int airforce)
{
	Card card = {
		.id = id,
		.defence = defence,
		.army = army,
		.navy = navy,
		.airforce = airforce};

	/*► 'name' e 'category' são ponteiros para instrings
	  ► strcpy() usado para copiar os valores da string
	*/

	strcpy(card.name, name);
	strcpy(card.category, category);

	return card;
}

/*
► Retorna o valor de um atríbuto específico da carta.
► Passando como parâmetro um valor de atríbuto.
*/

/*
► struct CardAttribute enum define constantes enumeradas
► Por padrão o compilador irá interpretar:
DEFENCE  = 0
ARMY     = 1
NAVY     = 2
AIRFORCE = 3
 */

int cardGetAttribute(Card card, CardAttribute attr)
{
	int attrValue;

	/*
	► Usa um switch para verificar qual atributo foi solicitado.
	*/
	switch (attr)
	{
	case AIRFORCE:
		attrValue = card.airforce;
		break;
	case NAVY:
		attrValue = card.navy;
		break;
	case DEFENCE:
		attrValue = card.defence;
		break;
	case ARMY:
		attrValue = card.army;
		break;
	default:
		attrValue = card.army;
		break;
	}
	return attrValue;
}
