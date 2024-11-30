#include <stdio.h>
#include <stdlib.h>


int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int start, end;
    FILE *file;

    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);

 if (start > end) {
 printf("Invalid range. Start should be less than or equal to End.\n");
  return 1;
    }
file = fopen("primes.txt", "w");
if (file == NULL) {
printf("Error opening file.\n");
   return 1;
    }

    printf("Finding prime numbers in the range [%d, %d]...\n", start, end);
    fprintf(file, "Prime numbers in the range [%d, %d]:\n", start, end);
int found = 0;
for (int i = start; i <= end; i++) {
 if (isPrime(i)) {
fprintf(file, "%d\n", i);
   found = 1;
        }
    }
 if (!found) {
        fprintf(file, "No prime numbers found in the given range.\n");
    }
fclose(file);
printf("Prime numbers have been saved to 'primes.txt'.\n");
    return 0;
}
