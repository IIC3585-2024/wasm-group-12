// index.js
function descomponerJS(mode) {
    // Obtener el número ingresado por el usuario
    let numero = parseInt(document.getElementById("numero").value);

    // Registrar el tiempo de inicio
    let startTime = performance.now();

    // Llamar a la función de descomposición de números primos
    if (mode === "bruteForce"){
        var factores = bruteForce(numero);
    }
    else if (mode === "primeDecomposition"){
        var factores = prime_decomposition(numero);
    }
    else {
        console.error("Modo no válido");
    }


    // Registrar el tiempo de finalización
    let endTime = performance.now();

    // Calcular el tiempo de ejecución en milisegundos
    let tiempoEjecucion = endTime - startTime;

    // Mostrar los resultados en el elemento con el ID "resultado"
    document.getElementById("resultado" + mode).innerText = "Factores primos: " + factores.join(", ");

    // Mostrar el tiempo de ejecución en el elemento con el ID "tiempo"
    document.getElementById("tiempo" + mode).innerText = tiempoEjecucion.toFixed(2) + " milisegundos";
}
