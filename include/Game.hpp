#ifndef GAME
#define GAME

#include <stddef.h>
#include "PlayerSymbolEnum.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"
// The game of Noughts and Crosses

class Game {
    private:
        GameBoard *board = new GameBoard();
        Player players[2];
        Player *currentPlayer;
    public:
        // Constructor
        Game();
        // Get the game board
        GameBoard *getBoard();
        // Get the current player
        Player *getCurrentPlayer();
        // Get player by symbol
        Player *getPlayerBySymbol(PlayerSymbolEnum symbol);
        // Get the winner
        char getWinner();
        // Check if the game is over
        bool isGameOver();
        // Check if the game is a draw
        bool isDraw();
        // Check if the game is won
        bool isWon();
        // Destructor
        ~Game() { };
};


#endif /* GAME */
