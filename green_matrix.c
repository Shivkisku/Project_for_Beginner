#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printGreen(const char* text) {
    printf("\033[0;32m%s\033[0m", text);
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    while (1) {
        int randomNum = rand() % 2;  // Generate a random number (0 or 1)

        if (randomNum == 0) {
            printGreen("0 ");
        } else {
            printGreen("1 ");
        }
    }

    return 0;
}
