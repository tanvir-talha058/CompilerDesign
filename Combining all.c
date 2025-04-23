#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isOperator(char c) {
    char operators[] = {'+', '-', '*', '/', '%', '=', '<', '>', '!',
                        '&', '|', '^', '~', '?', ':', ',', ';',
                        '(', ')', '[', ']', '{', '}', '#'};
    int size = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < size; i++) {
        if (c == operators[i]) {
            return true;
        }
    }
    return false;
}

bool isKeyword(const char *str) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isNumber(const char *str) {
    int i = 0;
    int length = strlen(str);
    bool hasDecimal = false;

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

bool isValidIdentifier(const char *str, char *message, int msgSize) {
    if (strlen(str) == 0) {
        snprintf(message, msgSize, "Empty string is not a valid identifier");
        return false;
    }

    if (isKeyword(str)) {
        snprintf(message, msgSize, "'%s' is a keyword and cannot be used as an identifier", str);
        return false;
    }

    if (!(isalpha(str[0]) || str[0] == '_')) {
        snprintf(message, msgSize, "Invalid first character '%c'. Identifiers must start with a letter or underscore", str[0]);
        return false;
    }

    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            snprintf(message, msgSize, "Invalid character '%c' at position %d. Identifiers can only contain letters, digits, and underscores", str[i], i + 1);
            return false;
        }
    }

    snprintf(message, msgSize, "'%s' is a valid C identifier", str);
    return true;
}

int main() {
    int choice;
    char input[50];
    char message[100];
    bool result;

    do {
        printf("\n=========== COMPILER TOKEN ANALYZER ===========\n");
        printf("1. Check if input is an Operator\n");
        printf("2. Check if input is a Keyword\n");
        printf("3. Check if input is a Number\n");
        printf("4. Check if input is a Valid Identifier\n");
        printf("5. Perform all checks on input\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        getchar(); // Consume the newline character left by scanf

        if (choice >= 1 && choice <= 5) {
            printf("Enter input string: ");
            scanf("%s", input);
        }

        switch (choice) {
            case 1:
                if (strlen(input) == 1) {
                    result = isOperator(input[0]);
                    printf("'%s' is %sa valid C operator.\n", input, result ? "" : "not ");
                } else {
                    printf("For operator check, input must be a single character.\n");
                }
                break;

            case 2:
                result = isKeyword(input);
                printf("'%s' is %sa C keyword.\n", input, result ? "" : "not ");
                break;

            case 3:
                result = isNumber(input);
                printf("'%s' is %sa valid number.\n", input, result ? "" : "not ");
                break;

            case 4:
                result = isValidIdentifier(input, message, 100);
                printf("%s\n", message);
                break;

            case 5:
                printf("\n===== ANALYSIS RESULTS FOR '%s' =====\n", input);

                if (strlen(input) == 1) {
                    result = isOperator(input[0]);
                    printf("Operator Check: %s\n", result ? "YES" : "NO");
                } else {
                    printf("Operator Check: N/A (input not a single character)\n");
                }

                result = isKeyword(input);
                printf("Keyword Check: %s\n", result ? "YES" : "NO");

                result = isNumber(input);
                printf("Number Check: %s\n", result ? "YES" : "NO");

                isValidIdentifier(input, message, 100);
                printf("Identifier Check: %s\n", strstr(message, "valid") != NULL ? "YES" : "NO");
                break;

            case 6:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}