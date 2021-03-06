/*
 * Trie.h
 *
 *  Created on: Jun 16, 2020
 *      Author: kotih
 */

#ifndef TRIE_H_
#define TRIE_H_

#define ALPHABET_SIZE 26
#include <stdbool.h>

typedef struct trien{
    bool isEOW;
    struct trien *next[ALPHABET_SIZE];
}TNode;

TNode *createTrieNode();
bool insertWordTrie(TNode *root, char word[]);
void printTrie(TNode *root, char word[], int last);
bool rinsertWordTrie(TNode *root, char word[]);
bool deleteWordFromTrie(TNode *root, char word[]);
bool hasWord(TNode *root, char word[]);
void printWordsWithPrefix(TNode *root, char prefix[]);
bool isLeaf(TNode *root);

#endif /* TRIE_H_ */
