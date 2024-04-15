function bruteForce(n){
    let factors = [];
    let initialNumber;

    for(let i = 2; i <= n/2; i++){
        initialNumber = 1;

        if (!isPrime(i)) {
            continue;
        }

        while (n % (i**initialNumber) === 0){
            factors.push(i);
            initialNumber++;
        }
    }
    return factors;
}

function isPrime(n){
    for(let i = 2; i <= n/2; i++){
        if(n % i === 0){
            return false;
        }
    }
    return true;
}