#include <opp/iostream.h>
#include <string.h>
#include <conio.h>
#include <opp/string.h>

#include "../include/game.hpp"

using namespace opp;

int main(void) {
    // set charset
    iocharmap(IOCHM_PETSCII_2);
    // initialize game
    cout << "Welcome to Tic Tac Toe!" << endl;
    Game game = Game();
    // while game not over:
    while (game.isGameOver() == false) {
        // Print the board
    //     display board
        cout << "Player " << game.getCurrentPlayer() << "'s turn:" << endl;
        cout << game.getBoardAsString() << endl;
    //     ask player for move
        string prompt = "Enter your move: ";
        string input = game.getPlayerMove(prompt);
        if (input.substr(0, 1) == "q") {
            break;
        }
        int *moveInt = game.parseMove(input);
        
    //  if move valid:
        if (game.isValidMove(moveInt[0], moveInt[1])) {
    //      update board
            game.updateBoard(moveInt[0], moveInt[1]);
    //      if player won or board full:
            if (game.isGameOver()) {
    //          display result
                char winner = game.getWinner();
                if (winner == ' ') {
                    cout << "Game over, it was a tie!" << endl;
                } else {
                    cout << "Game over, " << winner << " wins!" << endl;
                }
    //             end game
                break;
            } else {
    //         else:
    //             switch to next player
                game.switchPlayer();
            }
        } else {
    //     else:
    //         display error message
            cout << "Invalid move, please try again." << endl;
        }
    }
    // display result
    char winner = game.getWinner();
    if (winner == ' ') {
        cout << "Game over, it was a tie!" << endl;
    } else {
        cout << "Game over, Player " << winner << " wins!" << endl;
    }
    return 0;
}