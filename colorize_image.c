#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH  640  // Width of the image
#define HEIGHT 480  // Height of the image

typedef struct {
    unsigned char r, g, b;
} Pixel;

void convertToColor(Pixel colorImage[HEIGHT][WIDTH], unsigned char bwImage[HEIGHT][WIDTH]) {
    srand(time(NULL));  // Seed the random number generator

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned char intensity = bwImage[y][x];

            // Assign a random color to each pixel based on the intensity value
            colorImage[y][x].r = intensity;
            colorImage[y][x].g = rand() % 256;  // Random green component
            colorImage[y][x].b = rand() % 256;  // Random blue component
        }
    }
}

void saveColorImage(const char* filename, Pixel colorImage[HEIGHT][WIDTH]) {
    FILE* file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Unable to create the file.\n");
        return;
    }

    // Write the PPM header
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    // Write the pixel data
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fputc(colorImage[y][x].r, file);  // Red component
            fputc(colorImage[y][x].g, file);  // Green component
            fputc(colorImage[y][x].b, file);  // Blue component
        }
    }

    fclose(file);
    printf("Color image saved as %s.\n", filename);
}

int main() {
    unsigned char bwImage[HEIGHT][WIDTH];  // Black and white image
    Pixel colorImage[HEIGHT][WIDTH];       // Color image

    // Initialize the black and white image with random intensity values (0-255)
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bwImage[y][x] = rand() % 256;
        }
    }

    convertToColor(colorImage, bwImage);
    saveColorImage("color_image.ppm", colorImage);

    return 0;
}
