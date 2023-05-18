#include <stdio.h>
#include <conio.h>

#define WIDTH 20
#define HEIGHT 20

int gameOver;
int snakeX, snakeY;
int foodX, foodY;
int score;
int tailX[100], tailY[100];
int tailLength;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

void Setup() {
    gameOver = 0;
    dir = STOP;
    snakeX = WIDTH / 2;
    snakeY = HEIGHT / 2;
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
    score = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            if (i == snakeY && j == snakeX)
                printf("O");
            else if (i == foodY && j == foodX)
                printf("S");
            else {
                int printTail = 0;
                for (int k = 0; k < tailLength; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        printTail = 1;
                    }
                }
                if (!printTail)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snakeX;
    tailY[0] = snakeY;

    for (int i = 1; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            snakeX--;
            break;
        case RIGHT:
            snakeX++;
            break;
        case UP:
            snakeY--;
            break;
        case DOWN:
            snakeY++;
            break;
    }

    if (snakeX < 0 || snakeX >= WIDTH || snakeY < 0 || snakeY >= HEIGHT)
        gameOver = 1;

    for (int i = 0; i < tailLength; i++) {
        if (tailX[i] == snakeX && tailY[i] == snakeY)
            gameOver = 1;
    }

    if (snakeX == foodX && snakeY == foodY) {
        score++;
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;
        tailLength++;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
