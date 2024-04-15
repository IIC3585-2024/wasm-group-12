# WASM

## Prerequisites

- Have already `emscripten` latest version installed. For more information you can check the following [documentation](https://emscripten.org/docs/getting_started/downloads.html)

## Usage

 The following command is meant to be ran on the root directory of the project: 

```
emcc lib/prime_factorization.c -s WASM=1 -s EXPORTED_FUNCTIONS=_PrimeFactorization,_malloc,_free -o func/O3_factorization.js -s EXPORTED_RUNTIME_METHODS=["cwarp","getValue"] -s MODULARIZE=1 -s EXPORT_ES6=1 -sWASM_BIGINT -O1
```

Note: if you want to change the opimtimization process, you have to change the last flag with the one you are looking for: O2, O3, etc.

## Run on server

```
python3 -m http.server
```

this will host `index.html` on port `8000`. And now you are ready to go! 
