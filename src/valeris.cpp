#include "../lib/toolkit.h"
#include "../lib/combat.h"
#include "../lib/minigames.h"

int main()
{
#if defined(_WIN32) || defined(_WIN64)
  SetConsoleSize(800, 600);
#else
  SetTerminalSize(24, 80);
#endif

  // typePrint(getFileContent("../txt_files/intro.txt"));
  // combatV1(100, 100, 2000);
  TicTacToe game;
  game.startGame();
  return 0;
}