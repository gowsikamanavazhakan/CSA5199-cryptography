#include <stdio.h>
#include <math.h>

int main() {
    int keyLength = 25; // 25 slots to fill in the 5x5 matrix
    double possibleKeys = 1.0; // Initialize the count of possible keys
	int i;
    // Calculate the number of possible keys
    for ( i = 0; i < keyLength; i++) {
        possibleKeys *= (double)(keyLength - i);
    }

    // Express the result as a power of 2
    double log2Keys = log2(possibleKeys);

    printf("Approximate number of possible keys: %.0lf\n", possibleKeys);
    printf("Expressed as a power of 2: 2^%.0lf\n", log2Keys);

    return 0;
}
