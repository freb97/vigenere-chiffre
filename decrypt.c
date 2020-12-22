#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "src/common.h"
#include "src/crypt.h"

int main()
{
    assert(decrypt_char(' ', '!') == '~');

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

    char* decryptedString = decrypt_string(text, key);
    printf("Decrypted string: %s\n", decryptedString);

    free(decryptedString);
    free(text);
    free(key);
}