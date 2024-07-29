#include "../lib/toolkit.h"
#include "../lib/combat.h"

int main()
{
#if defined(_WIN32) || defined(_WIN64)
  SetConsoleSize(800, 600); // Set the console window size to 800x600 on Windows
#else
  SetTerminalSize(24, 80); // Set the terminal window size to 24 rows and 80 columns on Linux
#endif
  // typePrint(getFileContent("../txt_files/intro.txt"));
  combatV1(100, 100, 2000);

  return 0;
}