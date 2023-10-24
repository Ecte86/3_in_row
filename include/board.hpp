#ifndef BOARD
#define BOARD
#include <opp/string.h>
#include <opp/iostream.h>

using namespace opp;

#include "enums.hpp"
Player findWinner(string str);

char getWinnerRows(char board[3][3]);
char getWinnerCols(char board[3][3]);
char getWinnerDiags(char board[3][3]);




class Board {
  private:
    char board[3][3];

  public:
    Board();
    ~Board() {};
    string displayBoard();
    void updateBoard(char row, char col, char player);
    char getWinner();
    GameStatus getGameState();
    bool isValidMove(int row, int col);
    char *getBoard();
};


#endif /* BOARD */
