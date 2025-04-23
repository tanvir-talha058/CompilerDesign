#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool
isKeyword(const
char *str) {
    const
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };

    int
    numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return
            true;
        }
    }

    return
    false;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isKeyword(const char *str);

int main() {
    char
    input[50];

    printf("Enter a string to check: ");
    scanf("%s", input);

    if (isKeyword(input)) {
        printf("'%s' is a C keyword.\n", input);
    } else {
        printf("'%s' is not a C keyword.\n", input);
    }

    return 0;
}