#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char name[] = "Harry Potter";
    int i;

    for (i = 0; name[i] != '\0'; i++)
    {
        printf("%c", name[i]);
        fflush(stdout);
        usleep(200000);  // Sleep for 200 milliseconds
    }

    printf("\n");

    return 0;
}
