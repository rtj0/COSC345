/*!
@combat.cpp
@brief Doxygen example
@author Andrew Trotman
@copyright 2023 Andrew Trotman
*/
#include <iostream>
#include <string>
#include <cstdlib>     // For std::rand and std::srand
#include <ctime>       // For std::time
#include <chrono>      // For timing input



class combat{
public: 
// Function to print health bars for both player and enemy
void printHealth(int playerHealth, int enemyHealth)
{
    // Clear the previous output (assuming a terminal that supports ANSI escape codes)
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\033[A\033[K"; // Move cursor up and clear line
    }

    // Construct the health bars display
    std::string healthBars = "* Player Health: " + std::to_string(playerHealth) + "  Enemy Health: " + std::to_string(enemyHealth) + " *";
    std::string width = std::string(healthBars.length(), '*'); // Create a border line of '*' characters

    // Output the health bars with border
    std::cout << width + "\n"
              << healthBars << "\n"
              << width + "\n"
              << std::endl;
}

// Function for combat with directional inputs
void combatV1(int playerHealth, int enemyHealth, int difficulty)
{
    // Directional moves and their corresponding keyboard inputs
    std::string moves[] = {"\u2190", "\u2191", "\u2192", "\u2193"}; // ← ↑ → ↓
    std::string keyBoardEquivalent[] = {"a", "w", "d", "s"};
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

    while (playerHealth > 0 && enemyHealth > 0)
    {
        int random_number = std::rand() % 4; // Randomly select a move
        std::cout << moves[random_number] << std::flush; // Display the move

        auto start = std::chrono::high_resolution_clock::now(); // Record the start time
        std::string inputStr;

        while (true)
        {
            std::getline(std::cin, inputStr); // Get user input
            auto now = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = now - start; // Calculate elapsed time

            // Check if the input matches the expected key and is within the time limit
            if (inputStr == keyBoardEquivalent[random_number] && elapsed.count() < difficulty / 1000.0)
            {
                enemyHealth -= 5; // Successful attack
                printHealth(playerHealth, enemyHealth);
                break;
            }
            else if (elapsed.count() >= difficulty / 1000.0)
            {
                playerHealth -= 10; // Time limit exceeded
                printHealth(playerHealth, enemyHealth);
                break;
            }
            else
            {
                playerHealth -= 5; // Incorrect input
                printHealth(playerHealth, enemyHealth);
                break;
            }
        }
    }
    // Display result based on final health
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

// Function for a different type of combat
void combatV2(int playerHealth, int enemyHealth)
{
    char combatType[] = {'o', 'd', 's'}; // Possible combat types
    std::string options[] = {"Offensive", "Sneaky", "Defensive"};
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    int random_number = std::rand() % 3; // Randomly select a combat type

    while (playerHealth > 0 && enemyHealth > 0)
    {
        std::cout << "Please select an attack type"; // Prompt user (incomplete implementation)
    }

}









}
