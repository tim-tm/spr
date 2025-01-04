#include <stdio.h>
#include <string.h>

#define ALPHABET_LEN 26
#define MAX_MSG_LEN 512
#define MAX_KEY_LEN 512

static int fail_usage(void) {
    printf("Usage:\n\tEncryption: vigenere -e <message> <key>\n\tDecryption: vigenere -d <cipher> <key>\n");
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return fail_usage();
    }

    char *flag = argv[1];
    char *text = argv[2];
    size_t text_len = strnlen(text, MAX_MSG_LEN);
    char *key = argv[3];
    size_t key_len = strnlen(key, MAX_KEY_LEN);

    char extended_key[MAX_MSG_LEN];
    memset(extended_key, 0, MAX_MSG_LEN);
    for (size_t i = 0; i < text_len; ++i) {
        extended_key[i] = key[i%key_len];
    }

    if (strncmp(flag, "-e", 2) == 0) {
        char cipher[MAX_MSG_LEN];
        memset(cipher, 0, MAX_MSG_LEN);
        for (size_t i = 0; i < text_len; ++i) {
            cipher[i] = 65 + ((text[i] + extended_key[i]) % ALPHABET_LEN);
        }
        printf("(Key: %s)\n(Message: %s)\nCipher: %s\n", extended_key, text, cipher);
    } else if (strncmp(flag, "-d", 2) == 0) {
        char msg[MAX_MSG_LEN];
        memset(msg, 0, MAX_MSG_LEN);
        for (size_t i = 0; i < text_len; ++i) {
            msg[i] = 65 + ((text[i] - extended_key[i]) % ALPHABET_LEN);
        }
        printf("(Key: %s)\n(Cipher: %s)\nMessage: %s\n", extended_key, text, msg);
    } else {
        return fail_usage();
    }
    return 0;
}
