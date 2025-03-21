#include <curses.h>
#include <string.h>
#include "../include/game_data.h"

static void printCredits(char *lines[], int linesAmount, int y)
{
	for(int i = 0; i < linesAmount; i++)
	{
		int lineLen = strlen(lines[i]);
		mvprintw(y + i, (COLS - lineLen)/2, "%s", lines[i]);
	}
}
void creditsScreen(GameData *game)
{
	char *lines[] = {
		"  ____              _  __        __             ",
		" / ___|__ _ _ __ __| | \\ \\      / /_ _ _ __ ___ ",
		"| |   / _` | '__/ _` |  \\ \\ /\\ / / _` | '__/ __|",
		"| |__| (_| | | | (_| |   \\ V  V / (_| | |  \\__ \\",
		" \\____\\__,_|_|  \\__,_|    \\_/\\_/ \\__,_|_|  |___/",
		"-------------",
		"Planejamento: Luiz Gustavo Monteiro dos Reis, Matheus Ferreira Guedes",
		" ",
		"Programacao: Matheus Ferreira Guedes, Luiz Gustavo Monteiro dos Reis",
		" ",
		"Commit de teste: Pedro Juliani Goncalves",
		" ",
		"Supervisao: Bruno Romero Morales (em espirito)",
		" ",
		"Esquecer o notebook na aula do dia 19/03/2025: Gustavo Eklund Franca",
		" ",
		" ",
		" ",
		" ",
		" ",
		" ",
		"QQQQQQQP?'.__.__          -?$QQQQQQ",
		"QQQQQ? .=lvvnnvvvvosasss%%_, -?QQQQ",
		"QQQT'.|iivvooXXXmBWQQQWWWmmXo, \"4QQ",
		"QQ' .|||ilvoXZZZ#WWWWQWQQWZXSo(  ?Q",
		"Q'  -=||llnn2XXZZW#Wm#WWm##ZXon;  \"",
		"@    :ilIIvomXmmm#QmQQmWm#ZZX11>   ",
		"[   ._vuXXXq#WdQDXW$WWQWWmBZ1ll`   ",
		"    =v*!??YZXWn#CqemWW#WWWWmpii    ",
		"    ~ .._.  -\"iXvXIY\"^---|^!Y1>    ",
		"    .-- .     :nq#.    -*Y*|:=<.   ",
		"       :._;   _dQW;   _.    -=++   ",
		", ......=+==._jQWma=_ .+=` __s||=  ",
		"z-.=====;_|:)mQQQQmovi__<aadSoa>=.,",
		"h; :=ivoZ?<IXWWQQQWmuI#m#WmXoo1=<vm",
		"Qc .<iv?=::~)SWBWUY*1w,)AXZXnv}<<mQ",
		"QL,:<i=++;..:=*?!=._dUo|=*1IlIviiQQ",
		"QQ[=l.|:====+ii%iuooX1e||.<li+InmQQ",
		"QQk;v=v;: .<aa>s<a<%<; +i=%v|v2mQQQ",
		"QQQzis|=;=,. \"!!<{nXnsuo=<2sn1jQQQQ",
		"QQQm%>> =|ili<=aZZZX22on=i~venQQQQQ",
		"QQQQQc:  ||ivvvvnvvnnnviv+v}`]QQQQQ",
		"QQQQQW/::-=illvvvnnooXvi+:+`.WQQQQQ",
		"QQQQQQh::vviiv2oSoXS2X1c~` :i3QQQQQ",
		"QQQQQQQ. \"Ivsooonnn1v*~ ..||vn3QQQQ",
		"QQQQQQQc.;:+|+*li*=|:..=||iivon.]QQ",
		"QQQQQQP .:=++=|>||=+===+|vivvo}_jQQ"
	};
	int y = LINES;
	int linesAmount = sizeof(lines) / sizeof(lines[0]);

	timeout(850);
	while(getch() != 'q')
	{
		clear();
		printCredits(lines, linesAmount, y);
		mvprintw(0, 0, "Pressione 'q' para sair.");
		refresh();

		y--;
		if (y < 0 - linesAmount) y = LINES;
	}

	game->state = MAIN_MENU;
	timeout(-1);
}
