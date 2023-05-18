#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void processCommand(const char* command) {
    // Add your custom command processing logic here
    if (strcmp(command, "hello") == 0) {
        printf("Hello, world!\n");
    } else if (strcmp(command, "time") == 0) {
        // Get the current time and display it
        // You can use platform-specific libraries or system calls for this purpose
        printf("Current time: <implement your logic here>\n");
    } else if (strcmp(command, "exit") == 0) {
        // Exit the program
        printf("Exiting...\n");
        exit(0);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf(">> ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        processCommand(command);
    }

    return 0;
}
