#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <common.h>
#include <crypt.h>

int main()
{
    assert(encrypt_char('~', '!') == ' ');
    assert(decrypt_char(' ', '!') == '~');
    
    char* encryptedText = read_size_and_input();

    if (encryptedText == NULL)
    {
        return 1;
    }

    char* key = bruteforce_decrypt(encryptedText);

    if (key != NULL)
    {
        printf("Key found: %s\n", key);
    }
    else 
    {
        printf("Key could not be found...\n");
    }

    free(encryptedText);
    free(key);
}