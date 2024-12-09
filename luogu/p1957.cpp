#include <stdio.h>
#include <stdlib.h>

int n;
char type;

char buffer[100];
int main() {
  scanf("%d", &n);
  getchar();
  while (n--) {
    char curr;
    char *bp = buffer;
    while ((curr = getchar()) != '\n') {
      *(bp++) = curr;
    }
    *(bp++) = '\0';

    if (buffer[0] == 'a' || buffer[0] == 'b' || buffer[0] == 'c') {
      type = buffer[0];
      bp = &(buffer[1]);
    } else {
      bp = buffer;
    }

    int a, b;
    sscanf(bp, "%d%d", &a, &b);
    int res;
    if (type == 'a') {
      res = a + b;

      int cnt = printf("%d+%d=%d\n", a, b, res);
      printf("%d\n", --cnt);
    } else if (type == 'b') {
      res = a - b;
      int cnt = printf("%d-%d=%d\n", a, b, res);
      printf("%d\n", --cnt);
    } else if (type == 'c') {
      res = a * b;
      int cnt = printf("%d*%d=%d\n", a, b, res);
      printf("%d\n", --cnt);
    }
  }
}
