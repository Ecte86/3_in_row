#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <opp/string.h>

#include "../include/Game.hpp"

using namespace opp;

int main(void) {
    Game game = Game();
    iocharmap(IOCHM_PETSCII_2);

    //while (!game.isGameOver()) {
        // Print the board
        printf("%s\n", game.getBoard()->toString().tocstr());
    //}
    return 0;
}