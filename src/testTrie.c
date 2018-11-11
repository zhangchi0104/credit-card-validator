#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/trie.h"

int main(void) {
    Trie t = newTrie();
    insertBrand(t, "4", "Visa");
    insertBrand(t, "52", "MasterCard");
    insertBrand(t, "60", "RuPay");
    insertBrand(t, "6011", "Discover Card");
    printTrie(t);
}