#include<stdio.h>
char monocipher_encr(char);
char alpha[27][3] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, {
 'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' }, { 'i', 'l' }, {
 'j', 'm' }, { 'k', 'o' }, { 'l', 'p' }, { 'm', 'q' }, { 'n', 'r' }, {
 'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, {
 't', 'y' }, { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, {
 'y', 'e' }, { 'z', 'h' } };
char str[20];
int main() {
 char str[20], str2[20];
 int i;
 printf("\n Enter String..");
 gets(str);
 for (i = 0; str[i]; i++) {
 str2[i] = monocipher_encr(str[i]);
 }
 str2[i] = '\0';
 printf("\n Before Decryption..%s", str);
 printf("\n After Decryption..%s\n", str2);
}
char monocipher_encr(char a) {
 int i;
 for (i = 0; i < 27; i++) {
 if (a == alpha[i][0])
 break;
 }
 return alpha[i][1];
}

OUTPUT:
Enter String..goodmorning
Before Decryption..goodmorning
 After Decryption..jssuqswrlrj
