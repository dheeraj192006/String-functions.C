#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*)malloc(sizeof(int));  // Allocating memory for one integer

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 10;  // Assign value to the allocated memory
    printf("Value: %d\n", *p);
    free(p);  // Free allocated memory
    return 0;
}
