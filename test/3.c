#include <stdio.h>
int main() {
  int isPrime[999];
  for (int i = 0; i < 999; ++i) {
    isPrime[i] = 1;
  }
  for (int i = 2; i < 999; ++i) {
    if (isPrime[i] == 1) {
      for (int a = 2; a * i < 1000; ++a) {
        isPrime[a * i] = 0;
      }
    }
  }
  for (int i = 2; i < 999; ++i) {
    if (isPrime[i] == 1)
      printf("%d ", i);
  }
  return 0;
}
