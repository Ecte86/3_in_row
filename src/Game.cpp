#include "../include/Game.hpp"
#include "../include/Player.hpp"
#include "../include/GameBoard.hpp"
#include "../include/PlayerSymbolEnum.hpp"

// Constructor
Game::Game() {
    this->board = new GameBoard();
    PlayerSymbolEnum nought = (PlayerSymbolEnum)NOUGHT;
    PlayerSymbolEnum cross = (PlayerSymbolEnum)CROSS;
    Player player1 = Player(nought);
    Player player2 = Player(cross);
    this->players[0] = player1;
    this->players[1] = player2;
    this->currentPlayer = &this->players[0];
}

// Get the game board
GameBoard *Game::getBoard() {
    return this->board;
}

// Get the current player
Player *Game::getCurrentPlayer() {
    return this->currentPlayer;
}

// Get player by symbol
Player *Game::getPlayerBySymbol(PlayerSymbolEnum symbol) {
    for (int i = 0; i < 2; i++) {
        if (this->players[i].getSymbol() == symbol) {
            return &this->players[i];
        }
    }
}

// Get the winner
char Game::getWinner() {
    if (this->isWon()) {
        return this->currentPlayer->getSymbol();
    } else {
        return NONE;
    }
}

// Check if the game is over
bool Game::isGameOver() {
    if (this->board->isFull()) {
        return true;
    }
    return false;
}

// Check if the game is a draw
bool Game::isDraw() {
    if (this->isGameOver() && !this->isWon()) {
        return true;
    }
    return false;
}

// Check if the game is won
bool Game::isWon() {
    if (this->board->whoWon() != (PlayerSymbolEnum)NONE) {
        return true;
    }
    return false;
}