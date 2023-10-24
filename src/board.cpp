#include <stdio.h>
#include <opp/iostream.h>

#include "../include/board.hpp"
#include "../include/enums.hpp"

using namespace opp;

Player findWinner(string str) {
    if (str == "XXX") {
        return (Player)X;
    } else if (str == "OOO") {
        return (Player)O;
    } else {
        return (Player)NONE;
    }
}

Board::Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = NONE;
        }
    }
}

string Board::displayBoard() {
    string boardString = "";
    for (int i = 0; i < 3; i++) {
        boardString += " ";
        for (int j = 0; j < 3; j++) {
            boardString += board[i][j];
            if (j < 2) {
                boardString += " + ";
            }
        }
        if (i < 2) {
            boardString += "\n---+---+---\n";
        }
    }
    return boardString;
}

void Board::updateBoard(char row, char col, char player) {
    int row_i = -1;
    int col_i = -1;
    sscanf(&row, "%d", &row_i);
    sscanf(&col, "%d", &col_i);
    board[row_i][col_i] = player;
}

char Board::getWinner() {
    // check rows
    char winner = getWinnerRows(board);
    if (winner != ' ') {
        return winner;
    }
    // check columns
    winner = getWinnerCols(board);
    if (winner != ' ') {
        return winner;
    }
    // check diagonals
    winner = getWinnerDiags(board);
    return winner;
}

char getWinnerRows(char board[3][3]) {
    // check rows
    string row = "";
    for (int i = 0; i < 3; i++) {
        row = "";
        for (int j = 0; j < 3; j++) {
            row += board[i][j];
        }
        Player winner = findWinner(row);
        return (char)winner;
    }
}

char getWinnerCols(char board[3][3]) {
    // check columns
    string col = "";
    for (int i = 0; i < 3; i++) {
        col = "";
        for (int j = 0; j < 3; j++) {
            col += board[j][i];
        }
        Player winner = findWinner(col);
        return (char)(winner);
    }
}

char getWinnerDiags(char board[3][3]) {
    // check diagonals
    // left to right
    string diag = "";
    for (int i = 0; i < 3; i++) {
        diag += board[i][i];
    }
    // Check if we found a winner yet
    Player winner = findWinner(diag);
    // If not, reset diag and check the other diagonal
    if (winner == (Player)NONE) {
    // right to left
        diag = "";
        for (int i = 0; i < 3; i++) {
            diag += board[i][2 - i];
        }
        // Check if we found a winner now
        winner = findWinner(diag);
    }
    // Return the winner as a char
    if (winner == (Player)NONE) {
        return ' ';
    }
    return (char)(winner);
}

bool isFull(char board[3][3]) {
    bool full = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; i++) {
            if (board[i][j] == NONE) {
                full = false;
            }
        }
    }
    return full;
}

GameStatus Board::getGameState() {
    char winner = getWinner();
    if (winner == 'X') {
        return (GameStatus)WIN_PLAYER_X;
    } else if (winner == 'O') {
        return (GameStatus)WIN_PLAYER_O;
    } else if (isFull(board)) {
        return (GameStatus)DRAW;
    } else {
        return (GameStatus)IN_PROGRESS;
    }
}

bool Board::isValidMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    if (board[row][col] != (char)((Player)NONE)) {
        return false;
    }
    return true;
}