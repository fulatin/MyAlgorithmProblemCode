#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

const int N = (int)10e6 + 2;
ull stack[N];

ull *pointer;
int t;
void init() { pointer = stack; }

void push(ull x) { *(pointer++) = x; }

void pop() {
  if (pointer == stack) {
    printf("Empty\n");
    return;
  }
  pointer--;
}
void query() {
  if (pointer == stack) {
    printf("Anguei!\n");

  } else {
    printf("%llu\n", *(pointer - 1));
  }
}
void size() { printf("%lu\n", pointer - stack); }

int main() {
  scanf("%d", &t);
  while (t--) {
    init();
    int n;
    scanf("%d", &n);
    while (n--) {
      char buffer[10];
      scanf("%s", buffer);
      if (buffer[0] == 'p') {
        if (buffer[1] == 'o') {
          pop();
        } else {
          ull x;
          scanf("%llu", &x);
          push(x);
        }
      } else if (buffer[0] == 'q') {
        query();
      } else if (buffer[0] == 's') {
        size();
      }
    }
  }
}
