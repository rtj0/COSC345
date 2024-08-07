#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/* TicTacToe */
class TicTacToe
{
private:
    char squares[3][3] =
    {
        {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

public:
    void printBoard()
    {
        std::string arr[2] = { "\n   |   |   ", "\n___|___|___" };

        std::string top = std::string("\n ") + squares[0][0] + " | " + squares[0][1] + " | " + squares[0][2] + " ";
        std::string middle = std::string("\n ") + squares[1][0] + " | " + squares[1][1] + " | " + squares[1][2] + " ";
        std::string bottom = std::string("\n ") + squares[2][0] + " | " + squares[2][1] + " | " + squares[2][2] + " ";

        std::cout << arr[0] + top + arr[1] + arr[0] + middle + arr[1] + arr[0] + bottom + arr[0] << std::endl;
        std::cout.flush();
    }

    void clearBoard()
    {
        for (int i = 0; i < 12; i++)
        {
            std::cout << "\033[A\033[K";
            std::cout.flush();
        }
    }

    void computerTurn()
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        while (true)
        {
            int row = std::rand() % 3;
            int col = std::rand() % 3;

            if (squares[row][col] == ' ')
            {
                squares[row][col] = 'O';
                break;
            }
        }
        std::cout << "\n\n";
        clearBoard();
        printBoard();
    }

    bool checkForWin()
    {
        bool wasWin = false;
        // Horizontal Check
        for (int i = 0; i < 3; i++)
        {
            if (squares[i][0] == squares[i][1] && squares[i][0] == squares[i][2] && squares[i][0] != ' ')
            {
                wasWin = true;
            }
        }

        // Vertical check
        for (int i = 0; i < 3; i++)
        {
            if (squares[0][i] == squares[1][i] && squares[0][i] == squares[2][i] && squares[0][i] != ' ')
            {
                wasWin = true;
            }
        }

        // Diagonal Check
        if (squares[0][0] == squares[1][1] && squares[0][0] == squares[2][2] && squares[0][0] != ' ')
        {
            wasWin = true;
        }
        if (squares[0][2] == squares[1][1] && squares[0][2] == squares[2][0] && squares[0][2] != ' ')
        {
            wasWin = true;
        }
        return wasWin;
    }

    void startGame()
    {
        printBoard();
        int row, col;
        int count = 0;
        while (true)
        {
            std::cout << "\nEnter your move (row and column separated by a space, e.g., '1 1'): ";
            std::cin >> row >> col;

            if (std::cin.fail() || row < 1 || row > 3 || col < 1 || col > 3)
            {
                std::cin.clear();                                                   // clear the error flag on cin
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. Please enter numbers between 1 and 3." << std::endl;
                continue;
            }

            if (squares[row - 1][col - 1] != ' ')
            {
                std::cout << "That square is already taken. Please choose another one." << std::endl;
                continue;
            }

            squares[row - 1][col - 1] = 'X';
            clearBoard();
            printBoard();
            if (checkForWin())
            {
                std::cout << "You win!" << std::endl;
                break;
            }
            count++;
            if (count == 9)
            {
                std::cout << "Draw!" << std::endl;
                break;
            }

#ifdef _WIN32
            Sleep(1000); // Sleep for 1 second
#else
            sleep(1); // Sleep for 1 second
#endif

            computerTurn();
            if (checkForWin())
            {
                std::cout << "You lose!" << std::endl;
                break;
            }
            count++;
            if (count == 9)
            {
                std::cout << "Draw!" << std::endl;
                break;
            }
        }
    }
};
