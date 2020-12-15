#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int read_size() {
  unsigned int size;
  unsigned int num_assigned_attribs = scanf("%u ", &size);
  if (num_assigned_attribs != 1) {
    return 0;
  }
  return size;
}

char* read_input(unsigned int size) {
  char* input = calloc(size + 1, sizeof(char));
  char* curr_input = input;
  for (; curr_input < input + size; ++curr_input) {
    unsigned int num_assigned_attribs = scanf("%c", curr_input);
    if (num_assigned_attribs != 1) {
      return NULL;
    }
  }
  return input;
}

char* read_size_and_input() {
  unsigned int size = read_size();
  if (size == 0) {
    return NULL;
  }
  char* input = read_input(size);
  return input;
}