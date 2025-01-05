#include <stdio.h>
#include <string.h>

#define ALPHABET_LEN 26
#define MAX_MSG_LEN 512

static int fail_usage(void) {
    printf("Usage:\n\tEncryption: sub -e <message> <ciphertext alphabet>\n\tDecryption: sub -d <cipher> <ciphertext alphabet>\n");
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return fail_usage();
    }

    char *flag = argv[1];
    char *text = argv[2];
    size_t text_len = strnlen(text, MAX_MSG_LEN);
    char *key_alphabet = argv[3];
    size_t key_alphabet_len = strnlen(key_alphabet, MAX_MSG_LEN);

    char plain_alphabet[MAX_MSG_LEN];
    memset(plain_alphabet, 0, MAX_MSG_LEN);
    for (size_t i = 0; i < key_alphabet_len; ++i) {
        plain_alphabet[i] = i + 65;
    }

    if (strncmp(flag, "-e", 2) == 0) {
        char cipher[MAX_MSG_LEN];
        memset(cipher, 0, MAX_MSG_LEN);
        for (size_t i = 0; i < text_len; ++i) {
            int key_index = (text[i] - 65) % ALPHABET_LEN;
            cipher[i] = key_alphabet[key_index];
        }
        printf("(Plaintext alphabet:  %s)\n(Ciphertext alphabet: %s)\n(Message: %s)\nCipher: %s\n", plain_alphabet, key_alphabet, text, cipher);
    } else if (strncmp(flag, "-d", 2) == 0) {
        char msg[MAX_MSG_LEN];
        memset(msg, 0, MAX_MSG_LEN);
        for (size_t i = 0; i < text_len; ++i) {
            size_t j;
            for (j = 0; j < key_alphabet_len; ++j) {
                if (key_alphabet[j] == text[i]) break;
            }
            msg[i] = plain_alphabet[j];
        }
        printf("(Plaintext alphabet:  %s)\n(Ciphertext alphabet: %s)\n(Cipher: %s)\nMessage: %s\n", plain_alphabet, key_alphabet, text, msg);
    } else {
        return fail_usage();
    }
    return 0;
}
