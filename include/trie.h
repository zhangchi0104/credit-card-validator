#ifndef TRIE_H
#define TRIE_H

typedef struct trieRep* Trie;
typedef struct trieNode trieNode;

Trie newTrie();

void insertBrand(Trie, char *, char *); 

char *getBrand(Trie, char *);

void freeTrie(Trie);

void printTrie(Trie);
#endif