#ifndef CRYPT_H_
#define CRYPT_H_

char encrypt_char(char clear, char key);
char decrypt_char(char cipher, char key);
char* encrypt_string(char* cleartext, char* keyword);
char* decrypt_string(char* ciphertext, char* keyword);
char* bruteforce_decrypt(char* encryptedText);

#endif // CRYPT_H_