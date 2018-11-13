#include <stdio.h>
#include <stdlib.h>
#include "../../include/checkSum.h"
#include "../../include/trie.h"
#include <ctype.h>
#include <string.h>
static bool isNum(char);


char validateNumber(char *number) {
    int len = strlen(number);
    // check if there are 16 digits
    // 17 since the newline character counts

    int i;
    int sum = 0;
    int doubleFlag = 0;
    // starting from the rightmost difgit
    for (i = len - 2; i >= 0; i--, doubleFlag++) {
        int currDigit = ctoi(number[i]); // convert char to int
        // if current char is not a digit
        if(currDigit == -1) {
            return 2;
        }
        // doubles every second digit
        if (doubleFlag % 2 == 1) {
            currDigit *= 2;
        }

        // sums up all the digits
        // case 16: 1 + 6 = 7 
        sum += currDigit % 10 + currDigit / 10;
    }

    return (sum % 10 == 0);
}

void validateFromFile(char *fileName, Trie t) {
    FILE* numberList = fopen(fileName, "r");
    if (numberList == NULL) {abort();}
    char *currLine = calloc(1000, sizeof(char));
    int nValids = 0;
    int nScaned = 0; 
    while(!feof(numberList)) {
        fgets(currLine, 1000, numberList);
        char *brand = getBrand(t, currLine);
        printf("Card Brand: %s\n", brand);
        int res = validateNumber(currLine);
        switch(res) {
            case '1':
                printf("valid!\n");
                nValids++;
                break;
            case '2':
                printf("contains invalid character\n");
                break;
            case '0':
                printf("invalid!");
                break;
            default:
                break;
        }
        nScaned++;
    }
    printf("\nTotal card numbers scanned = %d\n", nScaned);
    printf("numbers of valid card number = %d\n", nValids);
    fclose(numberList);
    free(currLine);
}

int ctoi(char ch) {
    if(isNum(ch)) {
        return ch - '0';
    } else {
        return -1;
    }
}

static bool isNum(char ch) {
    return (ch >= '0' && ch <= '9');
} 

