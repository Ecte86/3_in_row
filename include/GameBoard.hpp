#ifndef GAMEBOARD
#define GAMEBOARD

#include <opp/string.h>
using namespace opp;

#include "BoardSquare.hpp"

class GameBoard {
    private:
        // The squares on the board, in a vector
        // of rows where each row is a vector of
        // squares
        BoardSquare squares[3][3];
        int emptySquares;
    public:
        // Constructor
        GameBoard();
        // Get the square at the given position
        BoardSquare getSquare(int row, int col);
        // Set the square at the given position
        void setSquare(int row, int col, PlayerSymbolEnum symbol);
        // Check if the square at the given position is empty
        bool isEmpty(int row, int col);
        // Check if the square at the given position is the given symbol
        bool isSymbol(int row, int col, PlayerSymbolEnum symbol);
        // Check if the board is full
        bool isFull();
        // Check if the board is won, and return the symbol of the winner
        PlayerSymbolEnum whoWon();
        // To string
        string toString();
        // Destructor
        ~GameBoard() { };

};


#endif /* GAMEBOARD */
