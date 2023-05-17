#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Struct to represent a pixel
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

// Function to convert a color pixel to black and white
Pixel convertToBlackAndWhite(Pixel colorPixel) {
    // Calculate the average of RGB values
    uint8_t average = (colorPixel.red + colorPixel.green + colorPixel.blue) / 3;
    
    // Set the average value to each channel
    Pixel bwPixel;
    bwPixel.red = average;
    bwPixel.green = average;
    bwPixel.blue = average;
    
    return bwPixel;
}

// Function to convert the whole image to black and white
void convertImageToBlackAndWhite(Pixel* imagePixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        imagePixels[i] = convertToBlackAndWhite(imagePixels[i]);
    }
}

int main() {
    // Read the image dimensions (assuming a 24-bit BMP image)
    int width, height;
    FILE* imageFile = fopen("input.bmp", "rb");
    
    if (imageFile == NULL) {
        printf("Failed to open the image file.\n");
        return 1;
    }
    
    fseek(imageFile, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, imageFile);
    fread(&height, sizeof(int), 1, imageFile);
    fclose(imageFile);
    
    // Read the image pixel data
    Pixel* imagePixels = (Pixel*)malloc(width * height * sizeof(Pixel));
    
    imageFile = fopen("input.bmp", "rb");
    if (imageFile == NULL) {
        printf("Failed to open the image file.\n");
        free(imagePixels);
        return 1;
    }
    
    fseek(imageFile, 54, SEEK_SET);
    fread(imagePixels, sizeof(Pixel), width * height, imageFile);
    fclose(imageFile);
    
    // Convert the image to black and white
    convertImageToBlackAndWhite(imagePixels, width, height);
    
    // Save the converted image
    imageFile = fopen("output.bmp", "wb");
    
    if (imageFile == NULL) {
        printf("Failed to create the output image file.\n");
        free(imagePixels);
        return 1;
    }
    
    fwrite(imagePixels, sizeof(Pixel), width * height, imageFile);
    fclose(imageFile);
    
    free(imagePixels);
    printf("Image converted to black and white successfully.\n");
    
    return 0;
}
