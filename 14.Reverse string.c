#include <stdio.h>
#include <string.h>
void reverseString(char *str) {
    int length = strlen(str),i;
    for ( i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}
int main() {
	int i;
    char test_cases[][20] = {"Y5mm/sa", "7yut02", "EryEq", "qEyrE"};
    for ( i = 0; i < 4; i++) {
        reverseString(test_cases[i]);
    }
    return 0;
}
