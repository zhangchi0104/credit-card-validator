#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/trie.h"
static void addBrand(Trie  t);

int main(void) {
    Trie t = newTrie();
    addBrand(t);
    printf("Please enter your card number(enter q to exit): ");

    char *input = calloc(1000, sizeof(char));
    fgets(input, 1000, stdin);
    char *brand;
    while(1){
        if(strcmp(input, "q\n")==0){break;}
        brand = getBrand(t, input);
        printf("Your card brand is \"%s\"\n", brand);
        free(brand);
        printf("\nPlease enter your card number(enter q to exit): ");
        fgets(input, 1000, stdin);
    }
    free(input);
    free(t);

}

static void addBrand(Trie  t) {
    insertBrand(t, "34", "American  Express");
    insertBrand(t, "37", "American Express");
    insertBrand(t, "31", "China T-Union");
    insertBrand(t, "62", "China Union Pay");
    
    // diners Club 300-305
    int i;
    for (i = 300;  i <= 305;  i++) {
        char *num = calloc(10, sizeof(char));
        sprintf(num, "%d", i);
        insertBrand(t, num, "Diners Club International");
        free(num);
    }
    insertBrand(t, "3095", "Diners Club International");
    insertBrand(t, "38", "Diners Club International");
    insertBrand(t, "39", "Diners Club International");

    insertBrand(t, "6011", "Discover Card");
    insertBrand(t, "64", "Discover Card");
    insertBrand(t, "65", "Discover Card");

    insertBrand(t, "60", "RuPay");
    insertBrand(t, "6521", "RuPay");

    insertBrand(t, "636", "InterPayment");

    // insert JCB 3528-3589
    for(i = 3258; i<=3589; i++) {
        char *num = calloc(10, sizeof(char));
        sprintf(num, "%d", i);
        insertBrand(t, num, "JCB");
        free(num);
    }

    insertBrand(t,"50", "Maestro");
    insertBrand(t,"56", "Maestro");
    insertBrand(t,"57", "Maestro");
    insertBrand(t,"58", "Maestro");
    insertBrand(t,"639", "Maestro");
    insertBrand(t,"67", "Maestro");

    insertBrand(t, "5019", "Dankort");

    insertBrand(t, "2200", "MIR");
    insertBrand(t, "2201", "MIR");
    insertBrand(t, "2202", "MIR");
    insertBrand(t, "2203", "MIR");
    insertBrand(t, "2204", "MIR");

    for(i = 222100; i<=272099; i++) {
        char *num = calloc(10, sizeof(char));
        sprintf(num, "%d", i);
        insertBrand(t, num, "MasterCard");
        free(num);
    }

    for(i = 51; i<=55; i++) {
        char *num = calloc(10, sizeof(char));
        sprintf(num, "%d", i);
        insertBrand(t, num, "MasterCard");
        free(num);
    }

    for(i = 979200; i<=979289; i++) {
        char *num = calloc(10, sizeof(char));
        sprintf(num, "%d", i);
        insertBrand(t, num, "Troy");
        free(num);
    }

    insertBrand(t, "4", "Visa");
    insertBrand(t, "1", "UATP");

    for(i = 506099; i <= 506198; i++) {
        char *num = calloc(10, sizeof(char));
        sprintf(num, "%d", i);
        insertBrand(t, num, "Verve");
        free(num);
    }

    for(i = 650002; i<=650027; i++) {
        char *num = calloc(10, sizeof(char));
        sprintf(num, "%d", i);
        insertBrand(t, num, "Verve");
        free(num);
    }



}