#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

int isUnique(char *word, char *words[], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

int main() {
    char* words[MAX_WORDS];
    int count = 0;

    printf("Enter words (type 'quit' to exit):\n");

    while (1) {
        char input[100];
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        if (isUnique(input, words, count)) {
            words[count] = strdup(input);
            count++;
        }
    }

    printf("Unique words entered:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }

    return 0;
}
