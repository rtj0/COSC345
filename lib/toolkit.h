#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <fstream>

#ifdef _WIN32
#include <windows.h>

void SetConsoleSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, width, height, TRUE);

    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_SIZEBOX);
}

#else
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

void SetTerminalSize(int height, int width)
{
    std::cout << "\e[8;50;100t";
}

#endif
// Function to mimic a delay
void delay(int milliseconds)
{
    auto start = std::chrono::high_resolution_clock::now();
    while (std::chrono::high_resolution_clock::now() - start < std::chrono::milliseconds(milliseconds))
    {
        // Busy-waiting loop to create a delay
    }
}

// Function to disable keyboard input
void disableInput()
{
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdin, 0);
#else
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON; // Disable canonical mode
    t.c_lflag &= ~ECHO;   // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
#endif
}

// Function to enable keyboard input
void enableInput()
{
#ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdin, ENABLE_ECHO_INPUT | ENABLE_INSERT_MODE | ENABLE_LINE_INPUT | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT | ENABLE_QUICK_EDIT_MODE | ENABLE_WINDOW_INPUT | ENABLE_VIRTUAL_TERMINAL_INPUT);
#else
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON; // Enable canonical mode
    t.c_lflag |= ECHO;   // Enable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    tcflush(STDIN_FILENO, TCIFLUSH);
#endif
}

void typePrint(std::string content)
{
    std::string token;
    std::stringstream ss(content);
    std::vector<std::string> tokens;

    while (getline(ss, token, '@'))
    {
        tokens.push_back(token);
    }

    disableInput();
    for (std::string &text : tokens)
    {
        for (char c : text)
        {
            std::cout << c << std::flush;
            delay(25);
        }
        enableInput();
        while (getchar() != '\n')
        {
        }
        disableInput();
    }
    enableInput();
}

std::string getFileContent(std::string fileName)
{
    std::ifstream file(fileName);
    std::string str;
    std::string file_contents;
    while (std::getline(file, str))
    {
        file_contents += str;
        file_contents.push_back('\n');
    }
    return file_contents;
}