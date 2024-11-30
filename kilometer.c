#include <stdio.h>

void convertMetersToKilometers() {
    double meters, kilometers;
    printf("Enter value in meters: ");
    scanf("%lf", &meters);
    kilometers = meters / 1000.0;
    printf("%.2lf meters = %.2lf kilometers\n", meters, kilometers);
}

void convertKilometersToMeters() {
    double kilometers, meters;
    printf("Enter value in kilometers: ");
    scanf("%lf", &kilometers);
    meters = kilometers * 1000.0;
    printf("%.2lf kilometers = %.2lf meters\n", kilometers, meters);
}

void convertCentimetersToMeters() {
    double centimeters, meters;
    printf("Enter value in centimeters: ");
    scanf("%lf", &centimeters);
    meters = centimeters / 100.0;
    printf("%.2lf centimeters = %.2lf meters\n", centimeters, meters);
}

void convertMetersToCentimeters() {
    double meters, centimeters;
    printf("Enter value in meters: ");
    scanf("%lf", &meters);
    centimeters = meters * 100.0;
    printf("%.2lf meters = %.2lf centimeters\n", meters, centimeters);
}

int main() {
    int choice;

    do {
        printf("\nUnit Converter Menu:\n");
        printf("1. Convert meters to kilometers\n");
        printf("2. Convert kilometers to meters\n");
        printf("3. Convert centimeters to meters\n");
        printf("4. Convert meters to centimeters\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convertMetersToKilometers();
                break;
            case 2:
                convertKilometersToMeters();
                break;
            case 3:
                convertCentimetersToMeters();
                break;
            case 4:
                convertMetersToCentimeters();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
