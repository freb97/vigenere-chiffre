# Vigenère-Chiffre

## Build

### encrypt

`gcc -I common -I crypt -o build/encrypt encrypt.c common/common.c crypt/crypt.c`

### decrypt

`gcc -I common -I crypt -o build/decrypt decrypt.c common/common.c crypt/crypt.c`

### brute-force decrypt

`gcc -I common -I crypt -o build/bfdecrypt bfdecrypt.c common/common.c crypt/crypt.c`

## Run

### encrypt

`build/encrypt < input/encrypt/input.txt`

Should return:

Encrypted string: vG]s#LOf7ePf<Y]hRQO]AKXsy[\_8T]U?G^"

### decrypt

`build/decrypt < input/decrypt/input.txt`

Should return:

Decrypted string: Das Pferd frisst keinen Gurkensalat.

### brute-force decrypt

`build/bfdecrypt < input/bfdecrypt/input.txt`

Should return:

Key found: ABCDE