#include <curses.h>
#include <string.h>

#include "../include/game_data.h"
#include "../include/player_list.h"
#include "../include/card.h"
#include "../include/deck.h"
#include "../include/countries.h"


static void blankScreen(Player *player);
static void drawHUD(WINDOW *hud, Player *player);
static void drawPlayerList(WINDOW *list, PlayerNode *node);
static void drawCard(WINDOW *card, Card carta);
void gameOver(Player *player);

/* Configurações de tamanho das subjanelas do jogo. */
static WINDOW *createHUD(void) {
	WINDOW *hud = newwin(4, PLAYER_NAME_MAXLEN + 11, 0, 0);
	return hud;
}
/*janela para exibir a lista de jogadores*/
static WINDOW *createPlayerListWindow(void) {
	const int listHeight = (LINES * 80) / 100;
	const int listWidth = PLAYER_NAME_MAXLEN + 12;
	WINDOW *list = newwin(listHeight, listWidth, 0, (COLS - listWidth));
	return list;
}
static WINDOW *createCardWindow(void) {
	const int cardWidth = 35;
	const int cardHeight = 16;

	WINDOW *card = newwin(cardHeight, cardWidth, (LINES - (cardHeight / 3))/2, (COLS - cardWidth)/2);
	return card;
}
/*********************************************/

void gameScreen(GameData *game) {
	WINDOW *gameOverWindow = newwin(4, 37, (LINES - 4)/2, (COLS - 37)/2);
	WINDOW *hudWindow = createHUD();
	WINDOW *playerListWindow = createPlayerListWindow();
	WINDOW *cardWindow = createCardWindow();

	PlayerNode *turnMaster = game->players;
	int key;
	CardAttribute attr;
	Deck *battleDeck = deckInitialize(game->maxCards);
	
	/* Loop principal do jogo */
	PlayerNode *temp;
	do {
		int turnMasterDeckSize = deckGetHeight(turnMaster->data.deck);
		/* Se o jogador possui todas as cartas, o jogo acbou e 
		 * resta apenas eliminar os outros jogadores;
		 */
		if (turnMasterDeckSize >= game->maxCards) {
			turnMaster = turnMaster->next;
			turnMasterDeckSize = deckGetHeight(turnMaster->data.deck);
		}
		/* Verifica se o jogador tem cartas para jogar. */
		if (turnMasterDeckSize > 0) {
			/* Mostra uma tela em branco para proteger suas cartas */
			blankScreen(&turnMaster->data);
			/* Mostra o HUD do jogador */
			drawHUD(hudWindow, &turnMaster->data);
			drawPlayerList(playerListWindow, turnMaster);
			/* Mostra a carta do jogador */
			drawCard(cardWindow, deckPeek(turnMaster->data.deck));
			/* Pede um atributo para o jogador */
			do {
				key = getch();
			} while (key < '1' || key > '4');
			switch(key) {
				case '1':
					attr = ARMY;
					break;
				case '2':
					attr = AIRFORCE;
					break;
				case '3':
					attr = NAVY;
					break;
				case '4':
					attr = DEFENCE;
			}
			/* Acha o jogador com o maior atributo */
			PlayerNode *winner = playerListHighestAttribute(game->players, attr);
			/* Guarda as cartas de todos. */
			temp = turnMaster;
			do {
				/* Evito pegar a carta do mestre da rodada para ter certeza de que ela
				 * estará no topo da pilha. Deste modo, ela estará no fundo quando
				 * eu transferir as cartas para o vencedor.
				 */
				if (deckGetHeight(temp->data.deck) > 0 && temp != turnMaster) {
					deckPush(battleDeck, deckPop(temp->data.deck));
				}
				temp = temp->next;
			} while(temp != turnMaster);
			if (deckGetHeight(turnMaster->data.deck) > 0) {
				deckPush(battleDeck, deckPop(turnMaster->data.deck));
			}

			/* Se houver emptate, volte para o começo do round */
			if (winner == NULL) continue;

			/* Caso o contrário, dê todas as cartas guardadas para o vencedor */
			while (deckGetHeight(battleDeck) > 0) {
				deckPush(winner->data.deck, deckPop(battleDeck));
			}

			/* 8 Se o vencedor for o mestre da rodada, volte ao início do round. */
			if (winner == turnMaster) continue;
			/* 9 Caso o contrário, vá para o próximo jogador */
			turnMaster = turnMaster->next;
		} else {
			erase();
			refresh();
			werase(gameOverWindow);
			temp = turnMaster;
			turnMaster = turnMaster->next;

			mvwaddstr(gameOverWindow, 1, (37 - strlen(temp->data.name)) /2, temp->data.name);
			mvwaddstr(gameOverWindow, 2, 1, "Nao tem mais cartas e foi eliminado");
			wrefresh(gameOverWindow);
			box(gameOverWindow, 0, 0);

			playerListRemove(&game->players, temp);
			getch();
		}
	} while(game->players != game->players->next);

	gameOver(&game->players->data);

	playerListFree(&game->players);

	delwin(hudWindow);
	delwin(playerListWindow);
	delwin(cardWindow);

	deckFree(battleDeck);
	game->state = MAIN_MENU;
}

static void blankScreen(Player *player) {
	char *msg = "Passe o computador para o jogador %s.";
	erase();
	mvprintw(LINES/2, (COLS - strlen(msg)) / 2, msg, player->name);
	refresh();
	getch();
	erase();
	refresh();
}

static void drawHUD(WINDOW *hud, Player *player) {
	werase(hud);
	mvwprintw(hud, 1, 1, "Jogador: %s", player->name);
	mvwprintw(hud, 2, 1, "Cartas: %d", deckGetHeight(player->deck));
	wborder(hud, '|','|','-','-','+','+','+','+');
	wrefresh(hud);
}

static void drawPlayerList(WINDOW *list, PlayerNode *node) {
	PlayerNode *temp = node;
	int listHeight;
	int listWidth;
	getmaxyx(list, listHeight, listWidth);

	werase(list);
	for (int i = 0; i < playerListLen(node) * 2; i += 2) {
		mvwprintw(list, i+1, 1, "%s", temp->data.name);
		mvwprintw(list, i+1, listWidth - 10, "Cartas: %d", deckGetHeight(temp->data.deck));
		mvwhline(list, i+2, 1,  '-', listWidth - 2);
		temp = temp->next;
		if (i >= listHeight) break;
	}
	wborder(list, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(list);
}

static void drawCard(WINDOW *card, Card carta) {
	int cardWidth;
	int cardHeight;
	getmaxyx(card, cardHeight, cardWidth);
	/* Estúpido, mas é o jeito */
	cardWidth++;

	werase(card);
	wborder(card, ':', ':', '=', '=', '.', '.', '.', '.');
	box(card, 0, '=');
	mvwaddstr(card, 1, 1, "Selecione um atributo");
	mvwprintw(card, cardHeight - 8, 2, "Pais: %s", carta.name);
	mvwprintw(card, cardHeight - 7, 2, "Categoria: %s", carta.category);
	mvwprintw(card, cardHeight - 5, 2, "1: Exercito: %d", carta.army);
	mvwprintw(card, cardHeight - 4, 2, "2: Aeronautica: %d", carta.airforce);
	mvwprintw(card, cardHeight - 3, 2, "3: Marinha: %d", carta.navy);
	mvwprintw(card, cardHeight - 2, 2, "4: Defesa: %d", carta.defence);

	wrefresh(card);
}

void gameOver(Player *player) {
	const int winHeight = 30;
	const int winWidth = 75;
	WINDOW *gameOverWindow = newwin(winHeight, winWidth, (LINES - winHeight)/2, (COLS - winWidth)/2);

	/* No raríssimo caso da mecânica de empate pegar todas as cartas de todos os usuários,
	 * nenhum jogador pode ser declarado como vencedor.
	 */
	if (deckGetHeight(player->deck) > 0) {
		mvwprintw(gameOverWindow,  1, 1, ".............................&...........................................");
		mvwprintw(gameOverWindow,  2, 1, "..............&;.&&&&&.&&&&&&&&...........+&.....&&&.....................");
		mvwprintw(gameOverWindow,  3, 1, ".....&&&&&&&&&&&&&&&&&:.&&&&&.......&&&&..&&&&&&&&&&&&&&&&&&&&&&&&.......");
		mvwprintw(gameOverWindow,  4, 1, "..&&&&&&&&&&&&&&+.&&....&&........:&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;.......");
		mvwprintw(gameOverWindow,  5, 1, ".&&....&&&&&&&&&&&&&&&&........&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.&&........");
		mvwprintw(gameOverWindow,  6, 1, ".......&&&&&&&&&&&&&.&&..........&&&&&&&&&&:&&&&&&&&&&&&&&&&&&...........");
		mvwprintw(gameOverWindow,  7, 1, "......&&&&&&&&&&&..............&&&..&&&&&&&&&&&&&&&&&&&&&&&&&:.&.........");
		mvwprintw(gameOverWindow,  8, 1, "......+&&&&&&&&................&&&&&..&..&&&&&&&&&&&&&&&&&&&.&&+.........");
		mvwprintw(gameOverWindow,  9, 1, ".......&&&&...&...............&&&&&&&&&&&&&&..&&&&&&&&&&&&&&.............");
		mvwprintw(gameOverWindow, 10, 1, "........&&&.&.&&&............&&&&&&&&&&&&+&&&&&...&&&.&&&&&..............");
		mvwprintw(gameOverWindow, 11, 1, "...........&&&..............&&&&&&&&&&&&&&&&......&&...&&&..&&...........");
		mvwprintw(gameOverWindow, 12, 1, ".............x&&&&&&..........&&&&&&&&&&&&&&&...........&....&$..........");
		mvwprintw(gameOverWindow, 13, 1, "..............&&&&&&&&.............&&&&&&&&&..............&&&&.&.........");
		mvwprintw(gameOverWindow, 14, 1, "..............&&&&&&&&&&&..........:&&&&&&...............&&......&&......");
		mvwprintw(gameOverWindow, 15, 1, "...............&&&&&&&&&............&&&&&&&.&..............&&..&&........");
		mvwprintw(gameOverWindow, 16, 1, "................&&&&&&&&............&&&&&.&&&................&&&&&&......");
		mvwprintw(gameOverWindow, 17, 1, ".................&&&&&..............&&&&&..&...............&&&&&&&&&.....");
		mvwprintw(gameOverWindow, 18, 1, ".................&&&&&...............&&&..................&&&&&&&&&......");
		mvwprintw(gameOverWindow, 19, 1, ".................&&&;..........................................&&.....&&.");
		mvwprintw(gameOverWindow, 20, 1, ".................$&&...........................................:....&&...");
		mvwprintw(gameOverWindow, 21, 1, "..................&&.....................................................");
		mvwprintw(gameOverWindow, 22, 1, ".........................................................................");
		mvwprintw(gameOverWindow, winHeight - 5, 1, "O jogador %s obteve todos os territorios e conquistou o mundo!", player->name);
	} else {

		mvwprintw(gameOverWindow, winHeight - 5, 1, "Todos os jogadores perderam seus territorios no conflito.");
		mvwprintw(gameOverWindow, winHeight - 4, 1, "Os que restaram estao condenados a viver no inferno que criaram.");
		mvwprintw(gameOverWindow, winHeight - 3, 1, "Enquanto o ceu cinza consome as estrelas que nao fugiram de desgosto,");
		mvwprintw(gameOverWindow, winHeight - 2, 1, "aqueles que ainda estao acordados testemunham a morte da esperanca.");

	}

	box(gameOverWindow, 0, 0);
	wrefresh(gameOverWindow);
	getch();
	delwin(gameOverWindow);
}
