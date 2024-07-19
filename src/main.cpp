#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

const int width = 12;
const int height = 22;

char board[height][width];

void initBoard() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 || x == width - 1 || y == height - 1) {
                board[y][x] = '#'; 
            } else {
                board[y][x] = ' ';
            }
        }
    }
}

void drawBoard() {
    std::cout << "\033[2J\033[1;1H"; 
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << board[y][x];
        }
        std::cout << "\n";
    }
}



int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void movePiece(int& x, int& y, char direction) {
    switch (direction) {
        case 'a':
            if (x > 1 && board[y][x - 1] == ' ') x--;
            break;
        case 'd': 
            if (x < width - 2 && board[y][x + 1] == ' ') x++;
            break;
        case 's': 
            if (y < height - 2 && board[y + 1][x] == ' ') y++;
            break;
    }
}

void placePiece(int x, int y, char piece) {
    board[y][x] = piece;
}

void removePiece(int x, int y) {
    board[y][x] = ' ';
}

int main() {
    initBoard();

    int x = width / 2; 
    int y = 1; 

    placePiece(x, y, '*'); 

    while (true) {
        if (kbhit()) {
            char ch = getchar();
            if (ch == 'q') { 
                break;
            }
            removePiece(x, y); 
            movePiece(x, y, ch);
            placePiece(x, y, '*'); 
        }

        drawBoard();
        usleep(500000); 
    }

    return 0;
}
