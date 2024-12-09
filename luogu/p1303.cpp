#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned char a[2005], b[2004];
int res[4005];

int main() {
  scanf("%s", a);
  scanf("%s", b);
  int cnta = strlen((char *)a);
  int cntb = strlen((char *)b);
  for (int i = 0; i < cnta; ++i) {
    a[i] = a[i] - '0';
  }
  for (int j = 0; j <= cntb; ++j) {
    b[j] = b[j] - '0';
  }
  for (int i = 0; i < cnta; ++i) {
    for (int j = 0; j < cntb; ++j) {
      res[i + j] += a[cnta - i - 1] * b[cntb - j - 1];
    }
  }
  for (int i = 0; i <= cnta + cntb + 10; ++i) {
    if (res[i] > 9) {
      res[i + 1] += res[i] / 10;
      res[i] %= 10;
    }
  }
  int pos;
  for (pos = 4003; res[pos] == 0 && pos > 0; --pos) {
  }
  for (int i = pos; i >= 0; --i) {
    printf("%d", res[i]);
  }
}
