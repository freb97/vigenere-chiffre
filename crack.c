#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/common.h"
#include "src/crypt.h"

int main()
{
    char* encryptedText = read_size_and_input();

    if (encryptedText == NULL)
    {
        return 1;
    }

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
                            break;
                        }
                    }
                }
            }
        }
    }

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