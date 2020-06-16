/*
 * main.cpp
 *
 *  Created on: Jun 16, 2020
 *      Author: kotih
 */

#include <stdio.h>
#include <stdlib.h>
#include "../header/Trie.h"

TNode *alphabetTrie[ALPHABET_SIZE];

void buildTrie(char ch) {
	FILE *fp = fopen("words.txt", "r");

	if (fp == NULL) {
		printf("Error opening dictionary file");
		fclose(fp);
		return;
	}

	TNode *root = createTrieNode();
	char temp[100];
	while (fscanf(fp, "%s", temp) == 1) {
		if (temp[0] == ch) {
			insertWordTrie(root, temp);
			break;
		}
	}

	while (fscanf(fp, "%s", temp) == 1) {
		if (temp[0] == ch)
			insertWordTrie(root, temp);
		else
			break;
	}

	fclose(fp);
	alphabetTrie[ch - 'a'] = root;
}

void initializeAlphabetTrie() {
	for (int i = 0; i < ALPHABET_SIZE; i++)
		alphabetTrie[i] = NULL;
}

char* convertToLowerCase(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}

	return str;
}

int main() {
	initializeAlphabetTrie();

	int words = 0;
	printf("How many words do you want to enter : ");
	scanf("%d", &words);

	while (words--) {
		printf("\nEnter word : ");
		char *word = (char*) malloc(sizeof(char) * 100);

		fflush(stdin);
		scanf("%s", word);

		word = convertToLowerCase(word);
		int index = word[0] - 'a';
		if (alphabetTrie[index] == NULL)
			buildTrie(word[0]);

		printf("Auto Suggest output : \n");
		printWordsWithPrefix(alphabetTrie[index], word);
		free(word);
	}

	return 0;
}
