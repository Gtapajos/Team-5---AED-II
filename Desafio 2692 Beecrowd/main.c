#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_changes, num_words, i, j;
    char old_char, new_char;
    scanf("%d %d", &num_changes, &num_words);

    // create a dictionary of changes to be made
    char changes[256] = {0}; // initialize the array to 0
    for (i = 0; i < num_changes; i++) {
        scanf(" %c %c", &old_char, &new_char);
        changes[(unsigned char)old_char] = new_char;
        changes[(unsigned char)new_char] = old_char;
    }

    // loop through each word and make necessary changes
    char words[num_words][100]; // assuming maximum word length is 100 characters
    for (i = 0; i < num_words; i++) {
        scanf(" %[^\n]", words[i]);
        for (j = 0; j < strlen(words[i]); j++) {
            if (changes[(unsigned char)words[i][j]]) {
                words[i][j] = changes[(unsigned char)words[i][j]];
            }
        }
    }
  
   for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
