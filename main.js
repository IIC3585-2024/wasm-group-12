const numero = parseInt(process.argv[2]);

function prime_decomposition(n) {
    let factors = [];
    for (let i = 2; i <= n/2; i++) {
        while (n % i === 0) {
            factors.push(i);
            n /= i;
        }
    }
    return factors;
}

console.log("Descomposición en factores primos de " + numero + ":")
console.log(prime_decomposition(numero))


