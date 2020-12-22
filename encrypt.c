#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "src/common.h"
#include "src/crypt.h"

int main()
{
    assert(encrypt_char('~', '!') == ' ');

    char* key = read_size_and_input();

    if (key == NULL)
    {
        return 1;
    }

    char* text = read_size_and_input();

    if (text == NULL)
    {
        return 1;
    }

    char* encryptedString = encrypt_string(text, key);
    printf("Encrypted string: %s\n", encryptedString);

    free(encryptedString);
    free(text);
    free(key);
}