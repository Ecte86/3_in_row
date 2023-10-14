
#include "../include/Player.hpp"

using namespace opp;

Player::Player() {
    this->symbol = NONE;
}

// Constructor
Player::Player(PlayerSymbolEnum symbol) {
    this->symbol = symbol;
}

// Get the player's symbol
PlayerSymbolEnum Player::getSymbol() {
    return this->symbol;
}

// Set the player's symbol
void Player::setSymbol(PlayerSymbolEnum symbol) {
    this->symbol = symbol;
}