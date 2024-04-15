#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isFactor(long num, long factor);

bool isPrime(long num);

long* numberDecompose(long num);

// int main() {
//     // long num;
//     // prlongf("Enter an longeger: ");
//     // scanf("%d", &num);

//     // prlongf("Prime numbers between 1 and %d are: ", num);
//     // for(long i = 2; i <= num; i++) {
//     //     if (isFactor(num, i) && isPrime(i)) {
//     //         prlongPrime(num, i);
//     //     }
//     // }

//     long* array = numberDecompose(0); 

//     for (long i = 0; array[i] != -1; i++) {
//         printf("%ld\n", array[i]);
//     }

//     return 0;
// }

void numberDecomposeRecursive(long num, long i, long** primes, long* count);

void numberDecomposeRecursive(long num, long i, long** primes, long* count) {
    if (i > num) {
        return;
    }
    
    // printf("num: %ld, i: %ld\n", num, i);
    // printf("isFactor: %d, isPrime: %d\n", isFactor(num, i), isPrime(i));

    if (isFactor(num, i) && isPrime(i)) {
        num = num / i;
        (*count)++;
        *primes = realloc(*primes, (*count + 1) * sizeof(long));
        (*primes)[*count - 1] = i;
        numberDecomposeRecursive(num, i, primes, count);
    } else {
        numberDecomposeRecursive(num, i + 1, primes, count);
    }
}

long* numberDecompose(long num) {



    long count = 0;
    long* primes;

    

    numberDecomposeRecursive(num, 2, &primes, &count);

    primes[count] = -1;
    return primes;
}

bool isFactor(long num, long factor) {
    return num % factor == 0;
}

bool isPrime(long num) {
    if (num <= 1) return false;
    for(long i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}
