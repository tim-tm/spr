#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LEN 26
#define MAX_MSG_LEN 512
#define MAX_KEY_LEN 512

static int fail_usage(void) {
    printf("Usage:\n\tEncryption: caesar -e <message> <key>\n\tDecryption: caesar -d <cipher> <key>\n");
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return fail_usage();
    }

    char *flag = argv[1];
    char *text = argv[2];
    size_t text_len = strnlen(text, MAX_MSG_LEN);

    // NOTE: atoi is unsafe and should not be used in a proper application
    int key = atoi(argv[3]);

    if (strncmp(flag, "-e", 2) == 0) {
        char cipher[MAX_MSG_LEN];
        memset(cipher, 0, MAX_MSG_LEN);
        for (size_t i = 0; i < text_len; ++i) {
            cipher[i] = text[i] + key;
        }
        printf("(Key: %d)\n(Message: %s)\nCipher: %s\n", key, text, cipher);
    } else if (strncmp(flag, "-d", 2) == 0) {
        char msg[MAX_MSG_LEN];
        memset(msg, 0, MAX_MSG_LEN);
        for (size_t i = 0; i < text_len; ++i) {
            msg[i] = text[i] - key;
        }
        printf("(Key: %d)\n(Cipher: %s)\nMessage: %s\n", key, text, msg);
    } else {
        return fail_usage();
    }
    return 0;
}
