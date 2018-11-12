#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/trie.h"

struct trieNode {
    char *brandName;
    trieNode **nextNum;
};

struct trieRep{
    int depth;
    trieNode **root;    
};


static trieNode  *insertNum(trieNode* t, char  *num,char *brandName, int lo, int hi);
static trieNode *newNode(char *brandName);
static void freeTrieNode(trieNode *t);
static int chtoi(char);
static void printTrieNode(trieNode *t, int currDigit);
Trie newTrie() {
    Trie n = malloc(sizeof(struct trieRep));
    assert(n != NULL);
    n->depth = 0;
    n->root = malloc(sizeof(trieNode *) * 10);
    int i = 0;
    for(i = 0; i < 10; i++) {
        n->root[i] = NULL;
    }
    return n;
}

void insertBrand(Trie t, char * num, char *brandName) {
    int hi = strlen(num);
    int head = chtoi(num[0]);
    if (head == -1) {
        fprintf(stderr, "Your card number contains invalid digits\n");
        abort();
    }
    t->root[head] = insertNum(t->root[head], num, brandName, 0, hi-1);
}

char *getBrand(Trie t, char*number) {
    int len = strlen(number);
    int cD = chtoi(number[0]);
    trieNode *curr = t->root[cD];
    int i;
    char *brand = NULL;
    for (i = 0; i < len;) {

        // no such digit 
        if (curr == NULL) {
            break;
        } else {
            brand = curr->brandName;
            i++;
            int nD = chtoi(number[i]);
            if(nD == -1) {
                printf("Your card number contains invalid digits\n");
                abort();
            }
            curr = curr->nextNum[nD];
        }
    }
    char *res = (brand == NULL) ? strdup("Unkown") : strdup(brand);
    return res;
}

void freeTrie(Trie t) {
  int i = 0;
  for(i = 0; i < 10; i++) {
      freeTrieNode(t->root[i]); 
  }
  free(t->root);
  free(t);
}
void printTrie(Trie t) {
    int i;
    for (i = 0; i < 10; i++) {
        printTrieNode(t->root[i], i);
        if(t->root[i] != NULL)
            putchar('\n');
    }
}
// ============================
static trieNode  *insertNum(trieNode* t, char  *num,char *brandName, int lo, int hi) {
    // recursive base case
    if (lo > hi) {return t;}
    // at root
    if (t == NULL) {
        // if lo is not end
        if(lo  < hi) {
            t = newNode(NULL); 
            int nD = chtoi(num[lo+1]);
            if (nD == -1) {
                printf("Your card number contains invalid digit\n");
                abort();
            }
            t->nextNum[nD] = insertNum(t->nextNum[nD], num, brandName, lo + 1, hi);
        // it is end
        } else {
            t = newNode(brandName);
        }
        return t;
    // node is not empty
    } else {
        // all digits are inserted
        if(lo == hi) {
            if (t->brandName != NULL) {
                printf("There is conflict in inserting %s into trie\n", brandName);
            } else {
                t->brandName = strdup(brandName);
            }
        // not there 
        } else {
            int nD = chtoi(num[lo+1]);
            t->nextNum[nD] = insertNum(t->nextNum[nD], num, brandName, lo + 1, hi);
        }
        return t;
    }
}

static trieNode *newNode(char *brandName) {
    trieNode *n = malloc(sizeof(trieNode));
    assert(n != NULL);
    if (brandName == NULL) {
        n->brandName = NULL;
    } else {
        n->brandName  = strdup(brandName);
    }
    n->nextNum = malloc(sizeof(trieNode *) * 10);
    assert(n->nextNum != NULL);
    int i;
    for(i = 0; i < 10; i++) {
        n->nextNum[i] = NULL;
        assert(n->nextNum != NULL);
    }
    return n;
}

static void freeTrieNode(trieNode *t) {
    if(t==NULL) {return;}
    int i = 0;
    for (i = 0; i < 10; i++) {
        freeTrieNode(t->nextNum[i]);
    }
    if(t->brandName != NULL) {free(t->brandName);}
    free(t);
}

static void printTrieNode(trieNode *t, int currDigit) {
    if (t == NULL) {return;}
    printf("%d ", currDigit);
    if(t->brandName != NULL) {
        printf("(%s)", t->brandName);
    } 
    int i = 0;
    for (i = 0; i< 10; i++) {
        if(t->nextNum[i] != NULL) {
            printTrieNode(t->nextNum[i], i);
            
        }
    }
    
}

static int chtoi(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else {
        return -1;
    }
}