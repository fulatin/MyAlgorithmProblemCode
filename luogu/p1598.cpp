#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int wdcnt[26];
int rmost[500];

int main() {
  char curr;
  while (scanf("%c", &curr) != EOF) {
    if (curr >= 'A' & curr <= 'Z') {
      wdcnt[curr - 'A']++;
    }
  }
  int hight = -1;
  for (int i = 0; i < 26; ++i) {
    hight = max(hight, wdcnt[i]);
  }
  for (int i = 0; i < 26; ++i) {
    int currh = wdcnt[i];
    for (int j = hight; j > hight - currh; --j) {
      rmost[j] = i;
    }
  }
  for (int i = 1; i <= hight; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (hight - wdcnt[j] < i) {
        printf("*");
        if (j < 25)
          printf(" ");
      }
      if (rmost[i] == j) {
        printf("\n");
        break;
      }
      if (hight - wdcnt[j] >= i) {
        printf(" ");
        if (j < 25)
          printf(" ");
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    putchar('A' + i);
    if (i < 25)
      printf(" ");
  }
  putchar('\0');
}
