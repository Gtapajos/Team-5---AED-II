#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_changes, num_words, i, j, k;
    char old_char, new_char;
    char words[50][50]; // assuming maximum word length is 50 characters
    scanf("%d %d", &num_changes, &num_words);

    // create a dictionary of changes to be made
    char changes[26];
    for (i = 0; i < num_changes; i++) {
        scanf(" %c %c", &old_char, &new_char);
        changes[old_char - 'a'] = new_char;
        changes[new_char - 'a'] = old_char;
    }

    // loop through each word and make necessary changes
    for (i = 0; i < num_words; i++) {
        scanf("%s", words[i]);
        for (j = 0; j < strlen(words[i]); j++) {
            if (changes[words[i][j] - 'a']) {
                words[i][j] = changes[words[i][j] - 'a'];
            }
        }
        printf("%s ", words[i]);
    }

    return 0;
}
