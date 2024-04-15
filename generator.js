function generateSolution() {
  let startTime = performance.now();
  const number = Number(document.getElementById("numero").value);

  const decomposedNumbersPtr = Module._numberDecompose(number);

  // Calcula la longitud del array
  let arrayLength = 0;
  while (Module.HEAP32[(decomposedNumbersPtr / 4) + arrayLength] != -1) {
    arrayLength++;
  }

  // Crea un nuevo array a partir de los valores en HEAP32
  const result = new Array(arrayLength);
  for (let i = 0; i < arrayLength; i++) {
    result[i] = Module.HEAP32[(decomposedNumbersPtr / 4) + i];
  }

  let endTime = performance.now();
  let tiempoEjecucion = endTime - startTime;

  // Mostrar los resultados en el elemento con el ID "resultado"
  document.getElementById("resultadoWasm").innerText = "Factores primos: " + result.join(", ");

  // Mostrar el tiempo de ejecución en el elemento con el ID "tiempo"
  document.getElementById("tiempoWasm").innerText = tiempoEjecucion.toFixed(2) + " milisegundos";
}
