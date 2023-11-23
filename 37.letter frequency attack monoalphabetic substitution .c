#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

// English letter frequency distribution (in percent)
const float englishFreq[ALPHABET_SIZE] = {
    8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094,
    6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929,
    0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150,
    1.974, 0.074
};

// Function to calculate the chi-squared statistic for a given distribution
float calculateChiSquared(const int *observedFreq) {
    float chiSquared = 0.0;

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        chiSquared += ((observedFreq[i] - englishFreq[i]) * (observedFreq[i] - englishFreq[i])) / englishFreq[i];
    }

    return chiSquared;
}

// Function to decrypt a monoalphabetic substitution cipher with a given key
void decrypt(const char *ciphertext, const char *key, char *plaintext) {
    for (size_t i = 0; ciphertext[i] != '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = (ciphertext[i] - key[ciphertext[i] - base] + 26) % 26 + base;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
}

// Function to perform a letter frequency attack on a monoalphabetic substitution cipher
void letterFrequencyAttack(const char *ciphertext, int topPlaintexts) {
    int observedFreq[ALPHABET_SIZE] = {0};
    int totalLetters = 0;

    // Calculate observed letter frequencies in the ciphertext
    for (size_t i = 0; ciphertext[i] != '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            observedFreq[ciphertext[i] - base]++;
            totalLetters++;
        }
    }

    // Calculate chi-squared statistic for each possible key
    for (int shift = 0; shift < ALPHABET_SIZE; ++shift) {
        char key[ALPHABET_SIZE];
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            key[i] = (i + shift) % ALPHABET_SIZE;
        }

        // Decrypt ciphertext with the current key
        char plaintext[256];
        decrypt(ciphertext, key, plaintext);

        // Calculate chi-squared statistic
        float chiSquared = calculateChiSquared(observedFreq);

        // Display the decrypted plaintext and chi-squared value
        printf("Key Shift: %d, Plaintext: %s, Chi-Squared: %.2f\n", shift, plaintext, chiSquared);
    }
}

int main() {
    const char *ciphertext = "Uifsf jt b tfdsfu djqifs xjuipvu uif mfuufs!";

    printf("Ciphertext: %s\n", ciphertext);

    int topPlaintexts;
    printf("Enter the number of top possible plaintexts to display: ");
    scanf("%d", &topPlaintexts);

    letterFrequencyAttack(ciphertext, topPlaintexts);

    return 0;
}

OUTPUT:
/tmp/vZQqUgQGMX.o
Ciphertext: Uifsf jt b tfdsfu djqifs xjuipvu uif mfuufs!
Enter the number of top possible plaintexts to display: 2
Key Shift: 0, Plaintext: Ntttt tt t tttttt tttttt ttttttt ttt tttttt!, Chi-Squared: 159.34
Key Shift: 1, Plaintext: Mssss ss s ssssss ssssss sssssss sss ssssss!, Chi-Squared: 159.34
Key Shift: 2, Plaintext: Lrrrr rr r rrrrrr rrrrrr rrrrrrr rrr rrrrrr!, Chi-Squared: 159.34
Key Shift: 3, Plaintext: Kqqqq qq q qqqqqq qqqqqq qqqqqqq qqq qqqqqq!, Chi-Squared: 159.34
Key Shift: 4, Plaintext: Jpppp pp p pppppp pppppp ppppppp ppp pppppp!, Chi-Squared: 159.34
Key Shift: 5, Plaintext: Ioooo oo o oooooo oooooo ooooooo ooo oooooo!, Chi-Squared: 159.34
Key Shift: 6, Plaintext: Hnnnn nn n nnnnnn nnnnnn nnnnnnn nnn nnnnnn!, Chi-Squared: 159.34
Key Shift: 7, Plaintext: Gmmmm mm m mmmmmm mmmmmm mmmmmmm mmm mmmmmm!, Chi-Squared: 159.34
Key Shift: 8, Plaintext: Fllll ll l llllll llllll lllllll lll llllll!, Chi-Squared: 159.34
Key Shift: 9, Plaintext: Ekkkk kk k kkkkkk kkkkkk kkkkkkk kkk kkkkkk!, Chi-Squared: 159.34
Key Shift: 10, Plaintext: Djjjj jj j jjjjjj jjjjjj jjjjjjj jjj jjjjjj!, Chi-Squared: 159.34
Key Shift: 11, Plaintext: Ciiii ii i iiiiii iiiiii iiiiiii iii iiiiii!, Chi-Squared: 159.34
Key Shift: 12, Plaintext: Bhhhh hh h hhhhhh hhhhhh hhhhhhh hhh hhhhhh!, Chi-Squared: 159.34
Key Shift: 13, Plaintext: Agggg gg g gggggg gggggg ggggggg ggg gggggg!, Chi-Squared: 159.34
Key Shift: 14, Plaintext: Zffff ff f ffffff ffffff fffffff fff ffffff!, Chi-Squared: 159.34
Key Shift: 15, Plaintext: Yeeee ee e eeeeee eeeeee eeeeeee eee eeeeee!, Chi-Squared: 159.34
Key Shift: 16, Plaintext: Xdddd dd d dddddd dddddd ddddddd ddd dddddd!, Chi-Squared: 159.34
Key Shift: 17, Plaintext: Wcccc cc c cccccc cccccc ccccccc ccc cccccc!, Chi-Squared: 159.34
Key Shift: 18, Plaintext: Vbbbb bb b bbbbbb bbbbbb bbbbbbb bbb bbbbbb!, Chi-Squared: 159.34
Key Shift: 19, Plaintext: Uaaaa aa a aaaaaa aaaaaa aaaaaaa aaa aaaaaa!, Chi-Squared: 159.34
Key Shift: 20, Plaintext: Tzzzz zz z zzzzzz zzzzzz zzzzzzz zzz zzzzzz!, Chi-Squared: 159.34
Key Shift: 21, Plaintext: Syyyy yy y yyyyyy yyyyyy yyyyyyy yyy yyyyyy!, Chi-Squared: 159.34
Key Shift: 22, Plaintext: Rxxxx xx x xxxxxx xxxxxx xxxxxxx xxx xxxxxx!, Chi-Squared: 159.34
Key Shift: 23, Plaintext: Qwwww ww w wwwwww wwwwww wwwwwww www wwwwww!, Chi-Squared: 159.34
Key Shift: 24, Plaintext: Pvvvv vv v vvvvvv vvvvvv vvvvvvv vvv vvvvvv!, Chi-Squared: 159.34
Key Shift: 25, Plaintext: Ouuuu uu u uuuuuu uuuuuu uuuuuuu uuu uuuuuu!, Chi-Squared: 159.34
