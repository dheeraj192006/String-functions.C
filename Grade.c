#include <stdio.h>

int main() {
    float marks;

    // Ask the user to enter the marks
    printf("Enter the marks (0-100): ");
    scanf("%f", &marks);

    // Check the grade based on the marks
    if (marks >= 90) {
        printf("Grade A\n");
    } else if (marks >= 80) {
        printf("Grade B\n");
    } else if (marks >= 70) {
        printf("Grade C\n");
    } else if (marks >= 60) {
        printf("Grade D\n");
    } else if (marks >= 50) {
        printf("Grade E\n");
    } else if (marks >= 0) {
        printf("Grade F\n");
    } else {
        printf("Invalid marks! Please enter marks between 0 and 100.\n");
    }

    return 0;
}
