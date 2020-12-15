#include <crypt.h>
#include <string.h>
#include <stdlib.h>

char encrypt_char(char clear, char key)
{
    clear -= 32;
    key -= 32;

    int cipher = clear + key;

    if (cipher > 94)
    {
        cipher -= 95;
    }

    clear = cipher;
    clear += 32;

    return clear;
}

char decrypt_char(char cipher, char key)
{
    cipher -= 32;
    key -= 32;

    int clear = cipher - key;

    if (clear < 0)
    {
        clear += 95;
    }

    cipher = clear;
    cipher += 32;

    return cipher;
}

char* encrypt_string(char* cleartext, char* keyword)
{
    int keywordIndex = 0;

    char* encryptedString = calloc(strlen(cleartext) + 1, sizeof(char));

    for (int i = 0; i < strlen(cleartext); i++)
    {
        if (keywordIndex > strlen(keyword) - 1)
        {
            keywordIndex = 0;
        }

        encryptedString[i] = encrypt_char(cleartext[i], keyword[keywordIndex]);

        keywordIndex++;
    }

    return encryptedString;
}

char* decrypt_string(char* ciphertext, char* keyword)
{
    int keywordIndex = 0;

    char* decryptedString = calloc(strlen(ciphertext) + 1, sizeof(char));

    for (int i = 0; i < strlen(ciphertext); i++)
    {
        if (keywordIndex > strlen(keyword) - 1)
        {
            keywordIndex = 0;
        }

        decryptedString[i] = decrypt_char(ciphertext[i], keyword[keywordIndex]);

        keywordIndex++;
    }

    return decryptedString;
}