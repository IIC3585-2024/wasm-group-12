# WASM

## Prerequisites

- Have wasm downloaded

## Usage

1. emcc main.c -s WASM=1 -s EXPORTED_FUNCTIONS=_isFactor,_isPrime,_numberDecompose,_numberDecomposeRecursive -o wasm.js
