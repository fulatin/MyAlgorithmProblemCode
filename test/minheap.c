#include <stdio.h>

int arr[1000];

inline int l(int x) { return x << 1; }
inline int r(int x) { return (x << 1) + 1; }
inline int fa(int x) { return x / 2; }

int bot = 0;

void insert(int x) {
  int pos = bot++;
  arr[pos] = x;
  while (arr[fa(pos)] > arr[pos]) {
    int tmp = arr[fa(pos)];
    arr[fa(pos)] = x;
    arr[pos] = arr[fa(pos)];
    pos = fa(pos);
  }
}

int top() { return arr[0]; }

int main() {
  insert(2);
  insert(1);
  insert(3);
  printf("%d", top());
  return 0;
}
