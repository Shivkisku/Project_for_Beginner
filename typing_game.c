#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORD_LENGTH 20
#define TIME_LIMIT_SECONDS 5

int main() {
    char word[MAX_WORD_LENGTH];
    char input[MAX_WORD_LENGTH];
    int score = 0;
    int round = 0;

    srand(time(NULL));

    printf("Welcome to the Typing Game!\n");

    while (1) {
        printf("\nRound %d\n", round + 1);

        // Generate a random word
        for (int i = 0; i < MAX_WORD_LENGTH - 1; i++) {
            word[i] = 'a' + rand() % 26;
        }
        word[MAX_WORD_LENGTH - 1] = '\0';

        printf("Type the word: %s\n", word);

        time_t startTime = time(NULL);

        // Read user input
        fgets(input, MAX_WORD_LENGTH, stdin);

        // Calculate elapsed time
        time_t endTime = time(NULL);
        double elapsedTime = difftime(endTime, startTime);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Check if the word is correct and within the time limit
        if (strcmp(input, word) == 0 && elapsedTime <= TIME_LIMIT_SECONDS) {
            printf("Correct! You earned 1 point.\n");
            score++;
        } else {
            printf("Wrong or time limit exceeded! Game over.\n");
            break;
        }

        round++;
        sleep(1); // Pause for 1 second before the next round
    }

    printf("Game over. Your score: %d\n", score);

    return 0;
}
