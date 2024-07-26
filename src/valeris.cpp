#include "toolkit.h"

void printHealth(int playerHealth, int enemyHealth)
{
  for (int i = 0; i < 5; i++)
  {
    std::cout << "\033[A\033[K";
  }

  std::string healthBars = "* Player Health: " + std::to_string(playerHealth) + "  Enemy Health: " + std::to_string(enemyHealth) + " *";
  std::string width = "";
  for (int i = 0; i < healthBars.length(); i++)
  {
    width += "*";
  }
  std::cout << width + "\n"
            << healthBars << "\n" + width + "\n"
            << std::endl;
}

void combatV1(int playerHealth, int enemyHealth, int difficulty)
{

  std::string moves[] = {"\u2190", "\u2191", "\u2192", "\u2193"};
  std::string keyBoardEquivalent[] = {"a", "w", "d", "s"};
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  while (playerHealth > 0 && enemyHealth > 0)
  {
    int random_number = std::rand() % 4;
    std::cout << moves[random_number] << std::flush;

    auto start = std::chrono::high_resolution_clock::now();
    std::string inputStr;

    while (true)
    {
      std::getline(std::cin, inputStr);
      auto now = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> elapsed = now - start;

      if (inputStr == keyBoardEquivalent[random_number] && elapsed.count() < difficulty / 1000.0)
      {
        enemyHealth -= 5;
        printHealth(playerHealth, enemyHealth);
        break;
      }
      else if (elapsed.count() >= difficulty / 1000.0)
      {
        playerHealth -= 10;
        printHealth(playerHealth, enemyHealth);
        break;
      }
      else
      {
        playerHealth -= 5;
        printHealth(playerHealth, enemyHealth);
        break;
      }
    }
  }
  if (playerHealth > 0)
  {
    std::cout << "You Win!";
  }
  else
  {
    std::cout << "You Lose!";
  }

  std::cout << moves[0] << std::endl; // End message or action
}

int main()
{
  // typePrint(getFileContent("../txt_files/intro.txt"));
  combatV1(100, 100, 2000);

  return 0;
}