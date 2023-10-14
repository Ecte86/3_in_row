#ifndef BOARDSQUARE
#define BOARDSQUARE
#include <opp/string.h>

using namespace opp;

#include "PlayerSymbolEnum.hpp"
// A square on the "board" of the game of Noughts and Crosses
class BoardSquare {
    private:
        // The symbol on the square
        char symbol;
    public:
        // Constructor
        BoardSquare();
        BoardSquare(PlayerSymbolEnum symbol);
        // Get the symbol on the square
        char getSymbol();
        // Set the symbol on the square
        void setSymbol(PlayerSymbolEnum symbol);
        // Check if the square is empty
        bool isEmpty();
        // Check if the square is the given symbol
        bool isSymbol(PlayerSymbolEnum symbol);
        // To string
        string toString();
        // Destructor
        ~BoardSquare() { };
};


#endif /* BOARDSQUARE */
