#include <stdio.h>

int main() {
  int a = 2, b = 3;
  int *p = &a;
  int *p2 = &b;
  int tmp;
  tmp = *p;
  *p = *p2;
  *p2 = tmp;
}
