#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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

bool
isValidIdentifier(const
char *str, char *message, int
msgSize) {
    if (strlen(str) == 0) {
        snprintf(message, msgSize, "Empty string is not a valid identifier");
        return
        false;
    }

    if (isKeyword(str)) {
        snprintf(message, msgSize, "'%s' is a keyword and cannot be used as an identifier", str);
        return
        false;
    }

    if (!(isalpha(str[0]) || str[0] == '_')) {
        snprintf(message, msgSize, "Invalid first character '%c'. Identifiers must start with a letter or underscore", str[0]);
        return
        false;
    }

    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            snprintf(message, msgSize, "Invalid character '%c' at position %d. Identifiers can only contain letters, digits, and underscores", str[i], i + 1);
            return
            false;
        }
    }

    snprintf(message, msgSize, "'%s' is a valid C identifier", str);
    return
    true;
}

int main() {
    char
    input[50];
    char
    message[100];

    printf("Enter a string to check: ");
    scanf("%s", input);

    isValidIdentifier(input, message, 100);
    printf("%s\n", message);

    return 0;
}