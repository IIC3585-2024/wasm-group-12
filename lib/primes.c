#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool isFactor(unsigned long long num, unsigned long long factor);

bool isPrime(unsigned long long num);

unsigned long long* numberDecompose(unsigned long long num, unsigned long long* size);

void numberDecomposeRecursive(unsigned long long num, unsigned long long i, unsigned long long** primes, unsigned long long* count);

void numberDecomposeRecursive(unsigned long long num, unsigned long long i, unsigned long long** primes, unsigned long long* count) {
    if (i > num) {
        return;
    }
    
    if (isFactor(num, i) && isPrime(i)) {
        num = num / i;
        (*count)++;
        *primes = realloc(*primes, (*count + 1) * sizeof(unsigned long long));
        (*primes)[*count - 1] = i;
        numberDecomposeRecursive(num, i, primes, count);
    } else {
        numberDecomposeRecursive(num, i + 1, primes, count);
    }
}

unsigned long long* numberDecompose(unsigned long long num, unsigned long long* size) {
    unsigned long long count = 0;
    unsigned long long* primes = NULL;

    numberDecomposeRecursive(num, 2, &primes, &count);

    primes[count] = -1;
    *size = count;
    return primes;
}

// Prime descomposition (O2)

unsigned long long* prime_decomposition(unsigned long long n, unsigned long long* size) {
    unsigned long long* factors = malloc(sizeof(unsigned long long));
    *size = 0;

    for (unsigned long long i = 2; i <= n; i++) {
        while (n % i == 0) {
            factors = realloc(factors, (*size + 1) * sizeof(unsigned long long));
            factors[*size] = i;
            (*size)++;
            n /= i;
        }
    }

    return factors;
}

// Brute force method (O3)

unsigned long long* bruteForce(unsigned long long n, unsigned long long* size) {
    unsigned long long* factors = (unsigned long long*)malloc(n * sizeof(unsigned long long));
    unsigned long long index = 0;
    unsigned long long initialNumber;

    if (isPrime(n)) {
        factors[index++] = n;
        *size = index;
        return factors;
    }

    for (unsigned long long i = 2; i <= n / 2; i++) {
        initialNumber = 1;

        if (!isPrime(i)) {
            continue;
        }

        while (n % (unsigned long long)pow(i, initialNumber) == 0) {
            factors[index++] = i;
            initialNumber++;
        }
    }

    *size = index;

    factors = (unsigned long long*)realloc(factors, index * sizeof(unsigned long long));

    return factors;
}

// Utils

bool isFactor(unsigned long long num, unsigned long long factor) {
    return num % factor == 0;
}

bool isPrime(unsigned long long num) {
    if (num <= 1) return false;
    for(unsigned long long i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}