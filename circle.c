#include <stdio.h>
#include <math.h>

void drawCircle(int radius) {
    int diameter = radius * 2;
    int center = radius;
    
    for (int y = 0; y <= diameter; y++) {
        for (int x = 0; x <= diameter; x++) {
            int distance = (int)sqrt(pow(x - center, 2) + pow(y - center, 2));
            
            if (distance == radius)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int radius = 5;
    drawCircle(radius);

    return 0;
}
