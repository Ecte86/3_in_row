#include "../include/GameBoard.hpp"
#include "../include/BoardSquare.hpp"

#include <opp/sstream.h>
#include <stdlib.h>
#include "../include/utilities.hpp"
using namespace opp;

GameBoard::GameBoard() {
    // Initialise the squares
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            BoardSquare square = BoardSquare();
            this->squares[row][col] = square;
        }
    }
    emptySquares = 9;
};

BoardSquare GameBoard::getSquare(int row, int col) {
    msg_assert(row >= 0 && row < 3, "getSquare(): Row out of bounds");
    msg_assert(col >= 0 && col < 3, "getSquare(): Column out of bounds");
    return squares[row][col];
}

void GameBoard::setSquare(int row, int col, PlayerSymbolEnum symbol) {
    msg_assert(row >= 0 && row < 3, "setSquare(): Row out of bounds");
    msg_assert(col >= 0 && col < 3, "setSquare(): Column out of bounds");
    squares[row][col].setSymbol(symbol);
    emptySquares--;
}

bool GameBoard::isEmpty(int row, int col) {
    msg_assert(row >= 0 && row < 3, "isEmpty(): Row out of bounds");
    msg_assert(col >= 0 && col < 3, "isEmpty(): Column out of bounds");
    return squares[row][col].isEmpty();
}

bool GameBoard::isSymbol(int row, int col, PlayerSymbolEnum symbol) {
    msg_assert(row >= 0 && row < 3, "isSymbol(): Row out of bounds");
    msg_assert(col >= 0 && col < 3, "isSymbol(): Column out of bounds");
    return squares[row][col].isSymbol(symbol);
}

bool GameBoard::isFull() {
    return emptySquares == 0;
}

PlayerSymbolEnum GameBoard::whoWon() {
    PlayerSymbolEnum winner = NONE;
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (squares[i][0].isSymbol((PlayerSymbolEnum) squares[i][1].getSymbol()) &&
            squares[i][0].isSymbol((PlayerSymbolEnum) squares[i][2].getSymbol()) &&
            squares[i][0].isSymbol((PlayerSymbolEnum) squares[i][0].getSymbol())) {
            winner = (PlayerSymbolEnum) squares[i][0].getSymbol();
            break;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (squares[0][i].isSymbol((PlayerSymbolEnum) squares[1][i].getSymbol()) &&
            squares[0][i].isSymbol((PlayerSymbolEnum) squares[2][i].getSymbol()) &&
            squares[0][i].isSymbol((PlayerSymbolEnum) squares[0][i].getSymbol())) {
            winner = (PlayerSymbolEnum) squares[0][i].getSymbol();
            break;
        }
    }
    // Check diagonals
    if (squares[0][0].isSymbol((PlayerSymbolEnum) squares[1][1].getSymbol()) &&
        squares[0][0].isSymbol((PlayerSymbolEnum) squares[2][2].getSymbol())) {
        winner = (PlayerSymbolEnum) squares[0][0].getSymbol();   
    }

    if (squares[0][2].isSymbol((PlayerSymbolEnum) squares[1][1].getSymbol()) &&
        squares[0][2].isSymbol((PlayerSymbolEnum) squares[2][0].getSymbol())) {
        winner = (PlayerSymbolEnum) squares[0][2].getSymbol();
    }
    switch (winner) {
        case CROSS:
        case NOUGHT:
        case NONE:
        default:
            msg_assert(false, "whoWon(): Invalid symbol");
    }
}

/// @brief ToString method for GameBoard
///        Loop through the squares and add them to a string
/// @return the string representation of the board
string GameBoard::toString() {
    ostringstream oss;

    // Add the top row
    oss << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Add the left column
            oss << " ";
            // Add the row number only if it's the first column
            if (j == 0) {
                oss << (i + 1);
            } else {
                // Add the square's string representation
                oss << getSquare(i, j).toString();
                if (j < 2) {
                    // Add the column divider
                    oss << "|";
                } else {
                    // New line
                    oss << endl;
                    oss << "  -----  " << endl;
                }
            }
        }
    }
}

// Path: src/GameBoard.cpp