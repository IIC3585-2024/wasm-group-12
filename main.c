#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isFactor(int num, int factor);

bool isPrime(int num);

int* numberDecompose(int num);

void numberDecomposeRecursive(int num, int i, int** primes, int* count);

void numberDecomposeRecursive(int num, int i, int** primes, int* count) {
    if (i > num) {
        return;
    }

    if (isFactor(num, i) && isPrime(i)) {
        num = num / i;
        (*count)++;
        *primes = realloc(*primes, (*count + 1) * sizeof(int));
        (*primes)[*count - 1] = i;
        numberDecomposeRecursive(num, i, primes, count);
    } else {
        numberDecomposeRecursive(num, i + 1, primes, count);
    }
}

int* numberDecompose(int num) {
    int count = 0;
    int* primes = NULL;

    numberDecomposeRecursive(num, 2, &primes, &count);

    primes[count] = -1;
    return primes;
}

bool isFactor(int num, int factor) {
    return num % factor == 0;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}
