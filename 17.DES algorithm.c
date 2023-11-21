#include <stdio.h>
#include <stdint.h>
static const int IP[] = { 2, 6, 3, 1, 4, 8, 5, 7 };
static const int IP_INV[] = { 4, 1, 3, 5, 7, 2, 8, 6 };
static const uint64_t KEY = 0x133457799BBCDFF1;
static const uint64_t CIPHERTEXT = 0x0123456789ABCDEF;
uint64_t permute(uint64_t input, const int *table, int size) {
 uint64_t result = 0;
 int i;
 for (i = 0; i < size; i++) {
 result |= ((input >> (64 - table[i])) & 1) << (size - 1 - i);
 }
 return result;
}
uint64_t des_decrypt(uint64_t ciphertext, uint64_t key) {
 uint64_t permuted_ciphertext = permute(ciphertext, IP, 64);
 uint64_t decrypted = permuted_ciphertext ^ key;
 decrypted = permute(decrypted, IP_INV, 64);
 return decrypted;
}
int main() {
 uint64_t decrypted = des_decrypt(CIPHERTEXT, KEY);

 printf("Ciphertext: 0x%016llX\n", CIPHERTEXT);
 printf("Decrypted: 0x%016llX\n", decrypted);
 return 0;
}

OUTPUT:
Ciphertext: 0x0123456789ABCDEF
Decrypted: 0x8B231170CDBC0B80
