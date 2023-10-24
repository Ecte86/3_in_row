#include <opp/iostream.h>
#include <opp/string.h>

#include "../include/enums.hpp"

using namespace opp;

char playerToChar(Player player) {
    if (player == (char)(Player)X) {
        return 'X';
    } else if (player == (char)(Player)O) {
        return 'O';
    } else {
        return ' ';
    }
}