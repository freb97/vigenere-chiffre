# Vigenère-Chiffre

## Build

### cmake

`cmake .`

`make`

## Run

### encrypt

`bin/encrypt < input/encrypt/input.txt`

Should return:

Encrypted string: vG]s#LOf7ePf<Y]hRQO]AKXsy[\_8T]U?G^"

### decrypt

`bin/decrypt < input/decrypt/input.txt`

Should return:

Decrypted string: Das Pferd frisst keinen Gurkensalat.

### crack

`bin/crack < input/crack/input.txt`

Should return:

Key found: ABCDE
