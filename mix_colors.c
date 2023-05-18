#include <stdio.h>

typedef struct {
    int red;
    int green;
    int blue;
} Color;

Color mixColors(Color color1, Color color2) {
    Color mixedColor;
    mixedColor.red = (color1.red + color2.red) / 2;
    mixedColor.green = (color1.green + color2.green) / 2;
    mixedColor.blue = (color1.blue + color2.blue) / 2;
    return mixedColor;
}

void printColor(Color color) {
    printf("RGB(%d, %d, %d)\n", color.red, color.green, color.blue);
}

int main() {
    Color color1 = {255, 0, 0};   // Red color
    Color color2 = {0, 0, 255};   // Blue color

    printf("Color 1: ");
    printColor(color1);

    printf("Color 2: ");
    printColor(color2);

    Color mixedColor = mixColors(color1, color2);

    printf("Mixed Color: ");
    printColor(mixedColor);

    return 0;
}
