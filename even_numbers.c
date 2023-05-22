#include <stdio.h>

int main() {
    int limit;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Even numbers up to %d:\n", limit);
    
    for (int i = 1; i <= limit; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
