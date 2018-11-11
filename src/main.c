#include <stdio.h>
#include <stdlib.h>
#include "checkSum.h"
#include <assert.h>

void acknowledge();

int main(int argc, char **argv) {
    acknowledge();
// ============================================
// validate card number from file
    if (argc > 1) {
        validateFromFile(argv[1]);
        return 0;
    }   

// ============================================
// validate number from stdin
    char *cardNumber = calloc(1000, sizeof(char));
    assert(cardNumber != NULL);
    fgets(cardNumber, 1000, stdin);
    printf("please enter your card number(no spaces in between): ");
    while(true) {
        int res = validateNumber(cardNumber);
        if (res == 1) {
            printf("your card number is valid!\n");
            break;
        } else if (res == 2) {
            printf("The card number your entered contains invalid digits\n");
        } else {
            printf("The card number your entered is invalid!\n"); 
        }
        printf("Please try again: ");
        fgets(cardNumber, 1000, stdin);
    }
    printf("\nPress any key to exit...");
    getchar();
    free(cardNumber);
    return 0;
}

void acknowledge() {
    printf("Welcome to this simple credit card validator(Version 1.0)!\n");
    printf("========================made by Alex======================\n");
    printf("Just letting you know:\n1.the method used  to valid your credit card number");
    printf(" is a purely mathematical-based.\n2.this app WILL NOT send your card number");
    printf(" to ANYONE and store ANY data inside your computer\n\n");
    printf("Now let's get started!\n");
}