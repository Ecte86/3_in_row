#include "../include/PlayerSymbolEnum.hpp"
#include "../include/BoardSquare.hpp"
#include <opp/sstream.h>
#include <opp/iostream.h>
#include <opp/string.h>

using namespace opp;

/// @brief Default constructor for BoardSquare
/// @details Sets the symbol to a space
/// @return BoardSquare
BoardSquare::BoardSquare() {
    symbol = ' ';
}
/// @brief Constructor for BoardSquare
/// @details Sets the symbol char to the given symbol for the square
/// @param symbol The symbol to set the square to
BoardSquare::BoardSquare(PlayerSymbolEnum symbol) {
    switch (symbol) {
        case CROSS:
            this->symbol = enumToString(symbol)[0];
            break;
        case NOUGHT:
            this->symbol = enumToString(symbol)[0];
            break;
        case NONE:
            this->symbol = enumToString(symbol)[0];
            break;
        default:
            break;
    }
}
/// @brief Get the symbol on the square
/// @return The symbol char on the square
char BoardSquare::getSymbol() {
    return symbol;
}
/// @brief Set the symbol on the square
/// @param symbol The symbol to set the square to
void BoardSquare::setSymbol(PlayerSymbolEnum symbol) {
    switch (symbol) {
        case CROSS:
            this->symbol = enumToString(symbol)[0];
            break;
        case NOUGHT:
            this->symbol = enumToString(symbol)[0];
            break;
        case NONE:
            this->symbol = enumToString(symbol)[0];
            break;
        default:
            break;
    }
}
/// @brief Check if the square is empty
/// @return True if the square is empty, false otherwise
bool BoardSquare::isEmpty() {
    return symbol == ' ';
}
/// @brief Check if the square is the given symbol
/// @param symbol The symbol to check against
bool BoardSquare::isSymbol(PlayerSymbolEnum symbol) {
    switch (symbol) {
        case CROSS:
            return this->symbol == enumToString(symbol)[0];
            break;
        case NOUGHT:
            return this->symbol == enumToString(symbol)[0];
            break;
        case NONE:
            return this->symbol == enumToString(symbol)[0];
            break;
        default:
            break;
    }
    return false;
}
/// @brief ToString method for BoardSquare
/// @return The symbol on the square
string BoardSquare::toString() {
    ostringstream ss;
    ss << " " << symbol << " ";
    return ss.str();
}