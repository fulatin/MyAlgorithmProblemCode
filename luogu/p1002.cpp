#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>

using namespace std;

long long int grid[30][30];

int bx, by, mx, my;

template <typename T> T rd() {
  T res = 0;
  char c = 0;
  while (!isdigit(c = getchar()))
    ;
  res = res * 10 + c - '0';
  while (isdigit(c = getchar())) {
    res = res * 10 + c - '0';
  }
  return res;
}

void render() {
  for (int i = 0; i <= bx; ++i) {
    for (int j = 0; j <= by; ++j) {
      printf("%11Ld", grid[i][j]);
    }
    cout << endl;
  }
}
int main() {
  bx = rd<int>();
  by = rd<int>();
  mx = rd<int>();
  my = rd<int>();
  grid[mx][my] = -1;
  for (int i = -2; i <= 2; ++i) {
    for (int j = -2; j <= 2; ++j) {
      if (abs(i) + abs(j) == 3) {
        if (mx + i >= 0 && my + j >= 0) {
          grid[mx + i][my + j] = -1;
        }
      }
    }
  }

  for (int i = 0; i <= bx; ++i) {
    if (grid[i][0] != -1) {
      grid[i][0] = 1;
    } else {
      break;
    }
  }
  for (int j = 0; j <= by; ++j) {
    if (grid[0][j] != -1) {
      grid[0][j] = 1;
    } else {
      break;
    }
  }
  for (int i = 1; i <= bx; ++i) {
    for (int j = 1; j <= by; ++j) {
      if (grid[i][j] != -1) {
        if (grid[i][j - 1] != -1)
          grid[i][j] += grid[i][j - 1];
        if (grid[i - 1][j] != -1)
          grid[i][j] += grid[i - 1][j];
      }
      // render();
    }
  }
  cout << grid[bx][by];
  return 0;
}
