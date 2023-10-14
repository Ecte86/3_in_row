#ifndef PLAYER
#define PLAYER

#include "PlayerSymbolEnum.hpp"

class Player {
    private:
        PlayerSymbolEnum symbol;
    public:
        // Default constructor
        Player();
        // Constructor
        Player(PlayerSymbolEnum symbol);
        // Get the player's symbol
        PlayerSymbolEnum getSymbol();
        // Set the player's symbol
        void setSymbol(PlayerSymbolEnum symbol);
        // Destructor
        ~Player() { };
};

#endif /* PLAYER */
