function decomposerJS(mode) {
    let factores;
    let numero = parseInt(document.getElementById("numero").value);
    let startTime = performance.now();

    if (mode === "bruteForceJS"){
        factores = bruteForce(numero);
    }
    else if (mode === "primeDecompositionJS"){
        factores = prime_decomposition(numero);
    }

    let endTime = performance.now();
    let tiempoEjecucion = endTime - startTime;
    assignToDom(mode, factores, tiempoEjecucion);
}

function decomposerC(mode) {
  let ptr;
  let sizePtr;
  const number = parseInt(document.getElementById("numero").value);
  let startTime = performance.now();

  sizePtr = Module._malloc(8); // unsigned long long

  if (mode === "bruteForceC") {
    ptr = Module.cwrap("bruteForce", "number", ["number", "number"])(number.toString(), sizePtr);
  } else if (mode === "primeDecompositionC") {
    ptr = Module.cwrap("prime_decomposition", "number", ["number, number"])(number.toString(), sizePtr);
  } else {
    ptr = Module.cwrap("numberDecompose", "number", ["number"])(number.toString(), sizePtr);
  }

  let size = Module.getValue(sizePtr, 'i64');
  Module._free(sizePtr);

  const result = new BigInt64Array(Module.HEAPU64.buffer, ptr, size);
  const resultArray = Array.from(result);

  let endTime = performance.now();
  let execTime = endTime - startTime;
  assignToDom(mode, resultArray, execTime);
}


function assignToDom(mode, factors, execTime){
    document.getElementById("resultado" + mode).innerText = "Factores primos: " + factors.join(", ");
    document.getElementById("tiempo" + mode).innerText = execTime.toFixed(2) + " milisegundos";
}
