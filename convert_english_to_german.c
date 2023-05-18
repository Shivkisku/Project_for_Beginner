#include <stdio.h>
#include <ctype.h>

char convertToGerman(char c) {
    switch (toupper(c)) {
        case 'A': return 'Ä';
        case 'E': return 'Ë';
        case 'I': return 'Ï';
        case 'O': return 'Ö';
        case 'U': return 'Ü';
        case 'S': return 'ẞ';
        default: return c;
    }
}

int main() {
    char input[100];
    char converted[100];
    int i = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        converted[i] = convertToGerman(input[i]);
        i++;
    }
    converted[i] = '\0';

    printf("Converted string: %s\n", converted);

    return 0;
}
