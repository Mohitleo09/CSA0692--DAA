#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main() {
    char input[10];
    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);
    bool valid = true;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i]) && input[i] != '\n') {
            valid = false;
            break;
        }
    }
    if (valid) {
        int number = 0;
        for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            number = number * 10 + (input[i] - '0');
        }
        int reversed = 0;
        while (number > 0) {
            reversed = reversed * 10 + (number % 10);
            number /= 10;
        }
        printf("Reversed number: %d\n", reversed);
    } else {
        printf("illegal input \n");
    }
    return 0;
}
