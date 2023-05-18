#include <stdio.h>
#include <string.h>

// Function to print text in green color
void printGreenText(const char* text) {
    printf("\033[0;32m%s\033[0m", text);
}

// Function to process user input and generate a response
const char* processInput(const char* input) {
    // Conversation patterns and responses
    const char* patterns[] = {
        "hi", "hello!",
        "how are you", "I'm doing well, thank you!",
        // Add more conversation patterns and responses here
    };
    const int numPatterns = sizeof(patterns) / sizeof(patterns[0]);

    // Convert input to lowercase for pattern matching
    char lowercaseInput[100];
    strcpy(lowercaseInput, input);
    for (int i = 0; lowercaseInput[i]; i++) {
        lowercaseInput[i] = tolower(lowercaseInput[i]);
    }

    // Search for a matching pattern and return the response
    for (int i = 0; i < numPatterns; i += 2) {
        if (strstr(lowercaseInput, patterns[i]) != NULL) {
            return patterns[i + 1];
        }
    }

    // If no match found, return a default response
    return "I'm sorry, I don't understand. Can you please rephrase?";
}

int main() {
    char input[100];

    printGreenText("Chatbot: ");
    while (1) {
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        // Exit loop if user enters "exit"
        if (strcmp(input, "exit") == 0) {
            break;
        }

        const char* response = processInput(input);
        printGreenText("Chatbot: ");
        printf("%s\n", response);
        printGreenText("User: ");
    }

    return 0;
}
