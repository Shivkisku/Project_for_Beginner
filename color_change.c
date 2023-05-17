#include <stdio.h>

int main() {
    printf("\033[0;31m"); // Set text color to red
    printf("This is red text.\n");

    printf("\033[0;32m"); // Set text color to green
    printf("This is green text.\n");

    printf("\033[0m"); // Reset text color to default

    printf("This is default text color.\n");

    return 0;
}
