#include <stdio.h>

int main() {
    int i;
    int repeat = 1000000000;  // Number of times to repeat the emoji

    // Set console text color to red
    printf("\033[0;31m");

    // Print the "I Love You" emoji repeatedly
    for (i = 0; i < repeat; i++) {
        printf("❤️ ");
    }

    // Reset console text color to default
    printf("\033[0m\n");

    return 0;
}
