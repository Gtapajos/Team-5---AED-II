#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ASIZE 256

struct RaitaAlgorithm {
int resultIndex[100];
int count;
};

int floorDivAlt(int x, int y) {
  int r = x / y;
  if ((x ^ y) < 0 && (r * y != x)) {
  r--;
  }
  return r;
}

void preprocessing(char* pattern, int m, int* bmBc) {
  for (int i = 0; i < ASIZE; i++) {
  bmBc[i] = m;
  }

  for (int i = 0; i < m - 1; i++) {
  bmBc[(int)pattern[i]] = m - i - 1;
  }
  }

bool search(struct RaitaAlgorithm* ra, char* pattern, char* descript, char* text) {
  int m = strlen(pattern);
  int n = strlen(text);
  char caracter = pattern[0];
  int bmbc[ASIZE];
  //printf("desc: %s\n", descript);
  preprocessing(pattern, m, bmbc);

  bool result = false;
  int j = 0;
  
  while (j <= (n - m)) {
      if (pattern[0] == text[j]) {
        ra->resultIndex[ra->count++] = j;
        text[j] = descript[0];
        result = true;
      }
      else if(descript[0] == text[j]){
            text[j] = pattern[0];
      }
    j += bmbc[(int)text[j + m - 1]];
  }

return result;
}

int main() {

    struct RaitaAlgorithm ra = {.count = 0};
    // w l
    // s m
    // e o
    // a b
    // c z
    // mbs loww 2017
    // tozwbde ceoire
    // ifmuwdosinbm
    int n_pattern = 0;
    int n_frases = 0;
    scanf("%d %d", &n_pattern, &n_frases);
    char patterns[n_pattern + 1];
    char descripts[n_frases + 1];
    char buffer[1000];
    for(int k = 0; k < n_pattern; k++){
        scanf(" %c %c", &patterns[k], &descripts[k]);
    }
    char *string_text = malloc(10000 * sizeof(char)); //aloca memoria para o texto
    string_text[0] = '\0'; // inicializa a string com null

    getchar();
    for (int i = 0; i < n_frases; i++) {
        fgets(buffer, sizeof(buffer), stdin); 
        buffer[strcspn(buffer, "\n")] = '\0'; // remove '\n' da entrada
        
        strcat(string_text, buffer); // concatena a string
        strcat(string_text, "\n"); // separa com \n para nova linha
    }

    

    for(int j = 0; j < n_pattern; j++){
      char pattern[2] = {patterns[j], '\0'};
      char desc[2] = {descripts[j], '\0'};
      bool result = search(&ra, pattern, desc, string_text);
    }

    printf("\n%s\n", string_text);
    free(string_text);

    return 0;
  }
