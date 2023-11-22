#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
int main() {
    int n = 25;  
    unsigned long long totalKeys = factorial(n);
    printf("Total number of possible keys: %llu\n", totalKeys);

    return 0;
}
OUTPUT:
Total number of possible keys: 7034535277573963776
