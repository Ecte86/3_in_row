#ifndef PLAYERSYMBOLENUM
#define PLAYERSYMBOLENUM

#include <opp/string.h>

using namespace opp;

enum PlayerSymbolEnum {
    NONE = 0,
    CROSS = 1,
    NOUGHT = 2,
    PLAYER_SYMBOL_ENUM_SIZE = 3
};

string enumToString(PlayerSymbolEnum symbol);
PlayerSymbolEnum stringToEnum(string symbol);

#endif /* PLAYERSYMBOLENUM */
