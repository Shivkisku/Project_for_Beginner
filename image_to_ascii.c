#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define ASCII_WIDTH 80
#define ASCII_HEIGHT 60

// Function to map pixel intensity to ASCII character
char intensityToAscii(uint8_t intensity) {
    char asciiChars[] = "@%#*+=-:. ";
    int numChars = sizeof(asciiChars) - 1;
    int step = 255 / numChars;
    int index = intensity / step;
    return asciiChars[index];
}

// Function to convert image to ASCII art
void convertToAscii(const uint8_t* pixels, int width, int height) {
    for (int y = 0; y < height; y += 2) {
        for (int x = 0; x < width; x++) {
            uint8_t pixelTop = pixels[(y * width) + x];
            uint8_t pixelBottom = pixels[((y + 1) * width) + x];
            uint8_t avgPixel = (pixelTop + pixelBottom) / 2;
            char asciiChar = intensityToAscii(avgPixel);
            putchar(asciiChar);
        }
        putchar('\n');
    }
}

int main() {
    // Read the image file
    FILE* file = fopen("input.pgm", "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open the image file.\n");
        return 1;
    }

    // Read the PGM image header
    char header[3];
    fread(header, sizeof(char), 3, file);
    if (header[0] != 'P' || header[1] != '5') {
        fprintf(stderr, "Invalid PGM image format.\n");
        fclose(file);
        return 1;
    }

    // Read the image dimensions
    int width, height;
    fscanf(file, "%d %d\n", &width, &height);

    // Read the maximum pixel value
    int maxValue;
    fscanf(file, "%d\n", &maxValue);
    if (maxValue != 255) {
        fprintf(stderr, "Invalid pixel value range.\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the image pixels
    uint8_t* pixels = (uint8_t*)malloc(width * height * sizeof(uint8_t));
    if (pixels == NULL) {
        fprintf(stderr, "Failed to allocate memory for pixels.\n");
        fclose(file);
        return 1;
    }

    // Read the image pixels
    fread(pixels, sizeof(uint8_t), width * height, file);
    fclose(file);

    // Convert the image to ASCII art
    convertToAscii(pixels, width, height);

    // Free the allocated memory
    free(pixels);

    return 0;
}
