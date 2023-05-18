#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, sum;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    printf("The sum is: %d\n", sum);

    char command[100];
    snprintf(command, sizeof(command), "echo %d | espeak", sum);
    system(command);

    return 0;
}
