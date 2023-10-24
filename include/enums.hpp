#ifndef ENUMS
#define ENUMS

enum Player { X = 'X', O = 'O', NONE = ' ' };
enum GameStatus {
    WIN_PLAYER_X,
    WIN_PLAYER_O,
    DRAW,
    IN_PROGRESS,
    GAMESTATUS_SIZE
};

char playerToChar(Player player);

#endif /* ENUMS */
