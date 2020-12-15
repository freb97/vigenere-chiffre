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

char* bruteforce_decrypt(char* encryptedText)
{
    char* guessedDecryption = calloc(strlen(encryptedText) + 1, sizeof(char));
    char* key = calloc(6, sizeof(char));

    for (int i = 65; i < 91; i++)
    {
        key[0] = i;

        for (int j = 65; j < 91; j++)
        {
            key[1] = j;
        
            for (int k = 65; k < 91; k++)
            {
                key[2] = k;
                
                for (int l = 65; l < 91; l++)
                {
                    key[3] = l;
                
                    for (int m = 65; m < 91; m++)
                    {
                        key[4] = m;
                        
                        guessedDecryption = decrypt_string(encryptedText, key);

                        if (
                            strstr(guessedDecryption, "again") != NULL &&
                            (
                                strstr(guessedDecryption, "the") != NULL ||
                                strstr(guessedDecryption, "thy") != NULL
                            )
                        ) {
                            return key;
                        }
                    }
                }
            }
        }
    }

    free(guessedDecryption);

    return NULL;
}