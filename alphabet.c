#include <stdio.h>

int main()
{
    char lowercase, uppercase;

    printf("Lowercase Alphabets: ");
    for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
    {
        printf("%c ", lowercase);
    }

    printf("\n\nUppercase Alphabets: ");
    for (uppercase = 'A'; uppercase <= 'Z'; uppercase++)
    {
        printf("%c ", uppercase);
    }

    return 0;
}
