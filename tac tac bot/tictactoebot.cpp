#include <iostream>
#include "grid.h"
#include "player.h"
#include "bot.h"
using namespace std;

int main()
{
    grid gameGrid; 
    player player1(1); // Makes a player object with playerNum = 1 (X)
    bot playercpu; // This is the bot

    int tempPos;
 
    gameGrid.print(); // Prints out a blank grid

    while (gameGrid.check() == -2) // Main game loop
    {
        do 
        {
            cout << "Player 1 please enter in a position: ";
            cin >> tempPos;
            gameGrid.print();
        } while (!player1.fill_grid(tempPos, gameGrid)); // Checks if player entered a valid position
        
        if (gameGrid.check() != -2) // Breaks game loop if grid has a winner or draw.
            break;

        playercpu.setPlayerNum(2); // Sets bot's playerNum to 2 (O).
        playercpu.fill_grid(playercpu.findMoveO(gameGrid), gameGrid); // Bot fills in gameGrid with its best move using inherited fill_grid() function from player class.
        gameGrid.print();
    }

    int temp = gameGrid.check(); // Figure out who won (or draw) once main game loop is broken. 

    if (temp == 1)
    {
        cout << "X wins!" << endl;
    }
    else if (temp == 2)
    {
        cout << "O wins!" << endl;
    }
    else if (temp == 0)
    {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
