#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int* bruteForce(int n, int* size) {
    int* factors = (int*)malloc(n * sizeof(int));
    int index = 0;
    int initialNumber;

    for (int i = 2; i <= n / 2; i++) {
        initialNumber = 1;

        if (!isPrime(i)) {
            continue;
        }

        while (n % (int)pow(i, initialNumber) == 0) {
            factors[index++] = i;
            initialNumber++;
        }
    }

    *size = index;

    factors = (int*)realloc(factors, index * sizeof(int));

    return factors;
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int size;
    int* factors = bruteForce(n, &size);

    printf("Prime decomposition of %d: ", n);
    for (int i = 0; i < size; i++) {
        printf("%d ", factors[i]);
    }
    printf("\n");

    free(factors);

    return 0;
}
