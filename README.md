# Vigenère-Chiffre

## Build

### encrypt

`gcc -I common -I crypt -o build/encrypt encrypt.c common/common.c crypt/crypt.c`

### decrypt

`gcc -I common -I crypt -o build/decrypt decrypt.c common/common.c crypt/crypt.c`

## Run

### encrypt

`build/encrypt`

### decrypt

`build/decrypt`