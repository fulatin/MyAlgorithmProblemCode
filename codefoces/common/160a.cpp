#include <cstdlib>
#include <iostream>

using namespace std;

int sum, n, arr[103];

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

template <typename T> T in() {
  T res = 0;
  char c = 0;
  while (!isdigit(c = getchar()))
    ;
  res = c - '0';
  while (isdigit(c = getchar())) {
    res = res * 10 + c - '0';
  }
  return res;
}

int main() {
  n = in<int>();
  for (int i = 1; i <= n; ++i) {
    arr[i] = in<int>();
    sum += arr[i];
  }
  qsort(arr + 1, n, sizeof(int), cmp);
  int tar = (sum) / 2;
  int curr = 0;
  for (int i = 1; i <= n; ++i) {
    curr += arr[i];
    if (curr > tar) {
      cout << i;
      return 0;
    }
  }
  cout << n;
  return 0;
}
