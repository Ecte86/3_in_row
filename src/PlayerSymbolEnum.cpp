#include "../include/PlayerSymbolEnum.hpp"
#include "../include/utilities.hpp"

using namespace opp;

// Get the symbol as a string
string enumToString(PlayerSymbolEnum symbol) {
    switch (symbol) {
        case NOUGHT:
            return "O";
        case CROSS:
            return "X";
        case NONE:
            return " ";
        default:
            msg_assert(false, "Invalid symbol");
    }
}

PlayerSymbolEnum stringToEnum(string symbol) {
    if (symbol == "O") {
        return NOUGHT;
    } else if (symbol == "X") {
        return CROSS;
    } else if (symbol == " ") {
        return NONE;
    } else {
        msg_assert(false, "Invalid symbol");
    }
}