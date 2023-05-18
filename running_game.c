#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 10

int playerX, playerY;
int obstacleX;
int score;

void Setup() {
    playerX = 2;
    playerY = HEIGHT / 2;
    obstacleX = WIDTH - 2;
    score = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < WIDTH; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == playerX && i == playerY)
                printf("R");
            else if (j == obstacleX && i == playerY)
                printf("X");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':
                playerY--;
                break;
            case 's':
                playerY++;
                break;
            case 'x':
                exit(0);
                break;
        }
    }
}

void Logic() {
    obstacleX--;

    if (obstacleX < 0) {
        obstacleX = WIDTH - 2;
        score++;
    }

    if (playerX == obstacleX && playerY == playerY)
        exit(0);
}

int main() {
    Setup();
    while (1) {
        Draw();
        Input();
        Logic();
        Sleep(10); // Delay for smoother animation
    }
    return 0;
}
