#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int x = 40;
    int y = 12;
    int blink = 0;

    while (1) {
        gotoxy(x, y);

        if (blink == 0) {
            printf("*");
            blink = 1;
        } else {
            printf(" ");
            blink = 0;
        }

        Sleep(500);  // Delay for half a second
    }

    return 0;
}
