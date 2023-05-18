#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char time_string[9];

    while (1) {
        // Get current time
        current_time = time(NULL);
        time_info = localtime(&current_time);

        // Format time as HH:MM:SS
        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

        // Print the time
        printf("\r%s", time_string);
        fflush(stdout);

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}
