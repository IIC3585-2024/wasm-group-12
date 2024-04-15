function generateSolution() {
  const input = document.getElementById('numberInput').value;
  const number = parseInt(input);

  const decomposedNumbersPtr = Module._numberDecompose(number);

  // Calcula la longitud del array
  let arrayLength = 0;
  while (Module.HEAP32[(decomposedNumbersPtr / 4) + arrayLength] != -1) {
    arrayLength++;
  }

  // Crea un nuevo array a partir de los valores en HEAP32
  const result = new Uint32Array(Module.HEAP32.buffer, decomposedNumbersPtr, arrayLength);

  const resultArray = Array.from(result);

  // Obtiene el div con id="numbersResult"
  const resultDiv = document.getElementById('numbersResult');

  // Crea una cadena con los valores del array
  const resultString = resultArray.join(', ');

  // Imprime el resultado en el div
  resultDiv.textContent = resultString;
}