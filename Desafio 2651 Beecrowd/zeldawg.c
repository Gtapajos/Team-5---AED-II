/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end_of_word;
} TrieNode;

TrieNode *get_node() {
    TrieNode *node = (TrieNode *) malloc(sizeof(TrieNode));
    if (node == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(1);
    }
    node->is_end_of_word = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, char *key) {
    int n = strlen(key);
    TrieNode *node = root;
    for (int i = 0; i < n; i++) {
        int index = key[i] - 'a';
        if (!node->children[index]) {
            node->children[index] = get_node();
        }
        node = node->children[index];
    }
    node->is_end_of_word = 1;
}

int forward_dawg_matching(TrieNode *root, char *string) {
    int n = strlen(string);
    int i = 0;
    TrieNode *node = root;
    while (i < n) {
        int index = string[i] - 'a';
        if (node->children[index]) {
            node = node->children[index];
            if (node->is_end_of_word) {
                return 1;
            } else if (string[i] == 'z' && i + 1 < n && string[i + 1] != 'e') {
                node = root;
            }
        } else {
            node = root;
        }
        i++;
    }
    return 0;
}

int main() {
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);

    TrieNode *root = get_node();

    insert(root, "zelda");

    if (forward_dawg_matching(root, string)) {
        printf("The string 'zelda' is present in the given string.\n");
    } else {
        printf("The string 'zelda' is not present in the given string.\n");
    }

    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end_of_word;
} TrieNode;

TrieNode *get_node() {
    TrieNode *node = (TrieNode *) malloc(sizeof(TrieNode));
    if (node == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(1);
    }
    node->is_end_of_word = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, char *key) {
    int n = strlen(key);
    TrieNode *node = root;
    for (int i = 0; i < n; i++) {
        int index = key[i] - 'a';
        if (!node->children[index]) {
            node->children[index] = get_node();
        }
        node = node->children[index];
    }
    node->is_end_of_word = 1;
}

int forward_dawg_matching(TrieNode *root, char *string) {
    int n = strlen(string);
    int i = 0;
    TrieNode *node = root;
    while (i < n) {
        int index = string[i] - 'a';
        if (node->children[index]) {
            node = node->children[index];
            if (node->is_end_of_word) {
                return 1;
            } else if (string[i] == 'z' && i + 1 < n && string[i + 1] != 'e') {
                node = root;
            } else if (string[i] == 'e' && i + 1 < n && string[i + 1] != 'l') {
                node = root;
            } else if (string[i] == 'l' && i + 1 < n && string[i + 1] != 'd') {
                node = root;
            } else if (string[i] == 'd' && i + 1 < n && string[i + 1] != 'a') {
                node = root;
            }
        }
        i++;
    }
    return 0;
}

int main() {
    char string[100];
    printf("Enter a string: ");
    scanf("%s", string);

    TrieNode *root = get_node();

    insert(root, "zelda");

    if (forward_dawg_matching(root, string)) {
        printf("The string 'zelda' is present in the given string.\n");
    } else {
        printf("The string 'zelda' is not present in the given string.\n");
    }

    return 0;
}
