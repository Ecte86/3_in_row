#ifndef GAME
#define GAME
#include "board.hpp"
#include <opp/iostream.h>
#include <opp/string.h>

using namespace opp;


/// Functions to:
class Game {
  private:
    Board *b;
    char currentPlayer;
    char winner;
    bool gameOver;

  public:
    Game();
    ~Game() {};
    // - initialize the board
    void initializeBoard();
    // - display the board
    string getBoardAsString();
    // - check for win conditions or draw
    char getWinner();
    bool isGameOver();
    // - get player's move
    char getCurrentPlayer();
    string getPlayerMove(string prompt);
    int *parseMove(string move);
    // - check if move is valid
    bool isValidMove(int row, int col);
    // - update board with player's move
    void updateBoard(int row, int col);
    // - switch players
    void switchPlayer();
    Board *getBoard();
};
#endif /* GAME */
