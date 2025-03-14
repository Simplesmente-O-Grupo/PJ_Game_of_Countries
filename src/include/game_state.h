#ifndef GAME_STATE_H
#define GAME_STATE_H
/**
 * @file game_state.h
 * @brief Define o estado atual do jogo.
 */

/**
 * Estado atual do jogo, dita qual tela o jogo
 * deve mostrar ao usuário
 */
typedef enum GameState {
	/**
	 * Menu inicial do jogo, ponto de partida de execução.
	 */
	MAIN_MENU,
	/**
	 * Tela de configurações para uma nova partida
	 */
	GAME_SETUP,
	/**
	 * Tela principal do jogo, onde acontecem as partidas
	 */
	IN_GAME,
	/**
	 * Tela com os nomes dos desenvolvedores
	 */
	CREDITS_SCREEN,
	/**
	 * Não é uma tela, mas sim um sinal de que o jogo deve encerrar sua execução.
	 */
	EXIT
} GameState;
#endif
