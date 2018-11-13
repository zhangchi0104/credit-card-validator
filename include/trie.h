#ifndef TRIE_H
#define TRIE_H

typedef struct trieRep* Trie;
typedef struct trieNode trieNode;

// allocate memory the trie
Trie newTrie();

// inserta prefix representing card brand and the brand into a trie
void insertBrand(Trie, char *, char *); 

// Given a card number, return its brand
// if it's not a known brand return unknown
char *getBrand(Trie, char *);

// free the trie 
void freeTrie(Trie);

// print info stored in the trie=
void printTrie(Trie);
#endif