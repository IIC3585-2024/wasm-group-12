#include <stdio.h>
#include <stdbool.h>

bool isFactor(int num, int factor);

bool isPrime(int num);

void printPrime(int num, int factor);

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are: ", num);
    for(int i = 2; i <= num; i++) {
        if (isFactor(num, i) && isPrime(i)) {
            printPrime(num, i);
        }
    }

    return 0;
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

void printPrime(int num, int factor){
    printf("%d ", factor);

    int division = num / factor;

    if (isFactor(division, factor)) {
        printPrime(division, factor);
    }

}