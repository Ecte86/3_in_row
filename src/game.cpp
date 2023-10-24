
#include "../include/game.hpp"

#include <opp/iostream.h>
#include <opp/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utilities.hpp"

using namespace opp;

/// Functions to:
// - initialize the board
// - display the board
// - get player's move
// - check if move is valid
// - update board with player's move
// - check for win conditions or draw
// - switch players

Game::Game() {
    initializeBoard();
    currentPlayer = (char)((Player)X);
    winner = (char)((Player)NONE);
    gameOver = false;
}

void Game::initializeBoard() {
    b = new Board();
}

string Game::getBoardAsString() {
    return b->displayBoard();
}

char Game::getWinner() {
    return b->getWinner();
}

bool Game::isGameOver() {
    GameStatus gameState = b->getGameState();
    switch (gameState) {
        case WIN_PLAYER_X:
            gameOver = true;
            winner = (char)((Player)X);
            break;
        case WIN_PLAYER_O:
            gameOver = true;
            winner = (char)((Player)O);
            break;
        case DRAW:
            gameOver = true;
            winner = (char)((Player)NONE);
            break;
        default:
            gameOver = false;
            break;
    }
    return gameOver;
}

char Game::getCurrentPlayer() {
    return currentPlayer;
}

string Game::getPlayerMove(string prompt) {
    if (prompt != nullptr) {
        cout << prompt << endl;
    }
    string move;
    cin >> move;
    return move;
}

int *parseMove(string move) {
    if (move.size() != 3) {
        return nullptr;
    } else if (move[1] != ',') {
        return nullptr;
    } else if (move[0] != '1' && move[0] != '2' && move[0] != '3') {
        return nullptr;
    } else if (move[2] != '1' && move[2] != '2' && move[2] != '3') {
        return nullptr;
    }
    int *parsedMove = new int[2];
    sscanf(move.tocstr(), "%d,%d", parsedMove[0], parsedMove[1]);
    return parsedMove;
}

bool Game::isValidMove(int row, int col) {
    return b->isValidMove(row, col);
}

void Game::updateBoard(int row, int col) {
    b->updateBoard(row, col, currentPlayer);
}

void Game::switchPlayer() {
    if (currentPlayer == (char)((Player)X)) {
        currentPlayer = (char)((Player)O);
    } else {
        currentPlayer = (char)((Player)X);
    }
}

Board *Game::getBoard() {
    return b;
}
