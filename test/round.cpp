#include <stdio.h>

int main() {
  int a, b;
  a = -5;
  b = 3;
  printf("向上取整\n");

  printf("a is %d, b is %d res: %d\n", a, b, (a + b - 1) / b);
  b = -3;
  printf("a is %d, b is %d res: %d\n", a, b, (a + b - 1) / b);
  b = -b;
  printf("a is %d, b is %d res: %d\n", a, b, (a + b - 1) / b);

  b = 3;

  printf("向下取整\n");
  printf("a is %d, b is %d res: %d\n", a, b, (a - b + 1) / b);
  b = -3;
  printf("a is %d, b is %d res: %d\n", a, b, (a - b + 1) / b);
}
