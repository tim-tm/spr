#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

static size_t uint_pow(size_t a, size_t b, size_t p) {
    if (b == 1) return a;
    return (((size_t)pow(a, b)) % p);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage:\tdh <modulus p> <base g> <alice secret> <bob secret>\n");
        return 1;
    }

    // NOTE: atoi is unsafe and should not be used in a proper application
    size_t p = atoi(argv[1]);
    size_t g = atoi(argv[2]);
    size_t a = atoi(argv[3]);
    size_t b = atoi(argv[4]);

    printf("p=%zu,g=%zu\n", p, g);

    size_t A = uint_pow(g, a, p);
    printf("alice:\n\tsecret: %zu\n\tpublic: %zu\n", a, A);

    size_t B = uint_pow(g, b, p);
    printf("bob:\n\tsecret: %zu\n\tpublic: %zu\n", b, B);

    size_t s_alice = uint_pow(B, a, p);
    size_t s_bob = uint_pow(A, b, p);
    printf("shared secrets:\n\talice: %zu\n\tbob: %zu\n", s_alice, s_bob);
    return 0;
}
