#include <iostream>
#include "grid.h"
#include "player.h"
#include "bot.h"
using namespace std;

int main()
{
    grid gameGrid;
    player player1(1);
    player player2(2);

    int tempPos;
    bool valid;

    // I should also make it so that it is random if you get player 1 or 2

    gameGrid.print();
    /*
    while (!gameGrid.check())
    {
        valid = true;
        do
        {
            cout << "Player 1 please enter in a position: ";
            cin >> tempPos;
            if (!player1.fill_grid(tempPos, gameGrid))
                valid = false;
            else
                valid = true;
            gameGrid.print();
        } while (!valid);
        
        if (gameGrid.check())
            break;

        do
        {
            cout << "Player 2 please enter in a position: ";
            cin >> tempPos;
            if (!player2.fill_grid(tempPos, gameGrid))
                valid = false;
            else
                valid = true;
            gameGrid.print();
        } while (!valid);
    }
    */

    int john[9] = {0,0,0,0,0,0,0,0,0};
    grid jimmy(john);
    jimmy.print();
    bot god;
    cout << god.minimax(jimmy, true);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
