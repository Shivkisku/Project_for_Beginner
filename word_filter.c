#include <stdio.h>
#include <string.h>

// Function to drop a specific word from the input string
void dropWord(char *input, const char *word) {
    char *token;
    char *prevToken = NULL;
    char *delimiters = " \t\n";  // Word delimiters

    // Tokenize the input string by whitespace characters
    token = strtok(input, delimiters);

    while (token != NULL) {
        // If the current token is not the word to be dropped
        if (strcmp(token, word) != 0) {
            // If it's not the first token, add a space before appending
            if (prevToken != NULL) {
                strcat(prevToken, " ");
            }
            strcat(prevToken, token);
            prevToken = token;
        }

        token = strtok(NULL, delimiters);
    }
}

int main() {
    char input[1000];
    const char word[] = "example";

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Remove the word from the input
    dropWord(input, word);

    printf("Filtered sentence: %s\n", input);

    return 0;
}
