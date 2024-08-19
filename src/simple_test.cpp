#include <cassert>
#include "minigames.cpp"

// Simple test function
void testTicTacToeInitialization()
{
    TicTacToe game;
    assert(game.checkForWin() == false); // A new game should not be in a win state
}

int main()
{
    testTicTacToeInitialization();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}