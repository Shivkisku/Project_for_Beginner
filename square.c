#include <stdio.h>

int main() {
    int side_length = 10;  // Length of each side in centimeters
    int i, j;

    // Loop to print the square
    for (i = 0; i < side_length; i++) {
        for (j = 0; j < side_length; j++) {
            // Print a '#' character to represent a pixel of the square
            printf("# ");
        }
        printf("\n");
    }

    return 0;
}
