#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool
isNumber(const
char *str) {
    int i = 0;
    int length = strlen(str);
    bool
    hasDecimal = false;

    if (str[0] == '+' || str[0] == '-') {
        i = 1;
        if (length == 1) return false;
    }

    for (; i < length; i++) {
        if (str[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isNumber(const char *str);

int main() {
    char
    input[50];

    printf("Enter a string to check: ");
    scanf("%s", input);

    if (isNumber(input)) {
        printf("'%s' is a valid number.\n", input);
    } else {
        printf("'%s' is not a valid number.\n", input);
    }

    return 0;
}