#include <stdio.h>

// Function to convert centimeters to meters
double cmToMeter(double cm) {
    return cm / 100.0;
}

// Function to convert centimeters to inches
double cmToInch(double cm) {
    return cm / 2.54;
}

// Function to convert inches to feet
double inchToFeet(double inch) {
    return inch / 12.0;
}

// Function to convert kilometers to millimeters
double kmToMillimeter(double km) {
    return km * 1000000.0;
}

int main() {
    double lengthInCm;

    printf("Enter the length in centimeters: ");
    scanf("%lf", &lengthInCm);

    double lengthInMeter = cmToMeter(lengthInCm);
    printf("Length in meters: %.2lf m\n", lengthInMeter);

    double lengthInInch = cmToInch(lengthInCm);
    printf("Length in inches: %.2lf inches\n", lengthInInch);

    double lengthInFeet = inchToFeet(lengthInInch);
    printf("Length in feet: %.2lf feet\n", lengthInFeet);

    double lengthInKm = cmToMeter(lengthInCm) / 1000.0;
    double lengthInMillimeter = kmToMillimeter(lengthInKm);
    printf("Length in millimeters: %.2lf mm\n", lengthInMillimeter);

    return 0;
}
