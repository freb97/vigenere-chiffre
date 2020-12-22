cmake_minimum_required(VERSION 3.10)

project(vigenere-chiffre)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(encrypt
  src/common.h
  src/common.c
  src/crypt.h
  src/crypt.c
  encrypt.c
)

add_executable(decrypt
  src/common.h
  src/common.c
  src/crypt.h
  src/crypt.c
  decrypt.c
)

add_executable(crack
  src/common.h
  src/common.c
  src/crypt.h
  src/crypt.c
  crack.c
)