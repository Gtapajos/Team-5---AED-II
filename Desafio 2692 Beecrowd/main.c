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
  printf("desc: %s\n", descript);
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
    char str[] =  "mbs loww 2017"; //"sam well 2017"
    char patterns[5] = "lmobz";
    char descripts[5] = "wseac";
    int size = 5;
    for(int j = 0; j < size; j++){
      char pattern[2] = {patterns[j], '\0'};
      char desc[2] = {descripts[j], '\0'};
      bool result = search(&ra, pattern, desc, str);
      //printf("\nresultado: %d", result);
    //   if (result) {
    //       for (int i = 0; i < ra.count; i++) {
    //           //printf("\n %c == %c", str[ra.resultIndex[i]], descripts[j]);
    //           str[ra.resultIndex[i]] = descripts[j];
    //       }
    //   }
      
    //   ra.count = 0;
    //   result = false;
    }

    printf("\n%s\n", str);

    return 0;
  }
