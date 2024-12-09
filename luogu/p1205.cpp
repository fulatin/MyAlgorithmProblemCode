#include <bits/stdc++.h>

using namespace std;

const int N = 12;
int n;
char rect[N][N], dest[N][N];

void rotate() {
  char tmp[N][N];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      tmp[j][n - i + 1] = rect[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      rect[i][j] = tmp[i][j];
    }
  }
}

void reflect() {
  char tmp[N][N];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      tmp[i][j] = rect[i][n - j + 1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      rect[i][j] = tmp[i][j];
    }
  }
}

bool isok() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (rect[i][j] != dest[i][j])
        return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> rect[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> dest[i][j];
    }
  }

  for (int i = 1; i <= 3; ++i) {
    rotate();
    if (isok()) {
      printf("%d\n", i);
      return 0;
    }
  }
  rotate();
  reflect();
  if (isok()) {
    printf("4");
    return 0;
  }

  for (int i = 1; i <= 3; ++i) {
    rotate();
    if (isok()) {
      printf("5");
      return 0;
    }
  }

  rotate();
  reflect();
  if (isok()) {
    printf("6");
    return 0;
  }

  printf("7");
  return 0;
}
