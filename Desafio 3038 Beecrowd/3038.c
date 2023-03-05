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

bool search(struct RaitaAlgorithm* ra, char* pattern, char* text) {
  int m = strlen(pattern);
  int n = strlen(text);
  char caracter = pattern[0];
  int bmbc[ASIZE];

  preprocessing(pattern, m, bmbc);

  bool result = false;
  int j = 0;
  
  while (j <= (n - m)) {
      if (pattern[0] == text[j]) {
        ra->resultIndex[ra->count++] = j;
        result = true;
      }
    j += bmbc[(int)text[j + m - 1]];
  }

return result;
}

int main() {
    FILE *fp;
    char *buffer;
    long file_size;

    fp = fopen("message.txt", "rb"); 
    if (fp == NULL) { 
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char*) malloc(file_size + 1);
    if (!buffer) {
        fclose(fp);
        printf("Erro de alocação\n");
        return 1;
    }

    fread(buffer, 1, file_size, fp);
    buffer[file_size] = '\0'; 

    fclose(fp);

    struct RaitaAlgorithm ra = {.count = 0};
    char *str = strdup(buffer);
    char patterns[6] = "@&!*#";
    char descripts[6] = "aeiou";
    int size = strlen(patterns);

    for(int j = 0; j < size; j++){
      char pattern[2] = {patterns[j], '\0'};
      bool result = search(&ra, pattern, str);
      if (result) {
          for (int i = 0; i < ra.count; i++) {
              str[ra.resultIndex[i]] = descripts[j]; 
          }
      }
      
      ra.count = 0;
      result = false;
    }

    printf("%s\n", str);

    free(buffer);
    free(str);

    return 0;
  }
