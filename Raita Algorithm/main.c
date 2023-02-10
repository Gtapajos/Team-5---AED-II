#include <stdio.h>
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
  char first = pattern[0];
  char middle = pattern[floorDivAlt(m, 2)];
  char last = pattern[m - 1];
  int bmbc[ASIZE];

  preprocessing(pattern, m, bmbc);

  bool result = false;
  int j = 0;
  
  while (j <= (n - m)) {
  if (m == 1) {
  if (pattern[0] == text[j]) {
  ra->resultIndex[ra->count++] = j;
  result = true;
  }
} 
  else {
  if (last == text[j + (m - 1)] &&
  first == text[j] &&
  middle == text[j + floorDivAlt(m, 2)] &&
  strncmp(pattern + 1, text + j + 1, m - 2) == 0) {
  ra->resultIndex[ra->count++] = j;
  result = true;
  }
    
  }
  j += bmbc[(int)text[j + m - 1]];
  }

return result;
}

int main() {
  struct RaitaAlgorithm ra = {.count = 0};
  bool result = search(&ra, "e", "pattern");
  if (result) {
  for (int i = 0; i < ra.count; i++) {
  printf("Index: %d\n", ra.resultIndex[i]);
  }
  } else {
  printf("Not Found\n");
  }
  return 0;
  }
