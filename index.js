// index.js
function descomponerJS() {
    // Obtener el número ingresado por el usuario
    let numero = parseInt(document.getElementById("numero").value);

    // Registrar el tiempo de inicio
    let startTime = performance.now();

    // Llamar a la función de descomposición de números primos
    let factores = prime_decomposition(numero);

    // Registrar el tiempo de finalización
    let endTime = performance.now();

    // Calcular el tiempo de ejecución en milisegundos
    let tiempoEjecucion = endTime - startTime;

    // Mostrar los resultados en el elemento con el ID "resultado"
    document.getElementById("resultado").innerText = "Descomposición de " + numero + " en factores primos: " + factores.join(", ");

    // Mostrar el tiempo de ejecución en el elemento con el ID "tiempo"
    document.getElementById("tiempo").innerText = "Tiempo de ejecución: " + tiempoEjecucion.toFixed(2) + " milisegundos";
}
