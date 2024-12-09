#include <bits/stdc++.h>

using namespace std;
typedef double db;
int c[11][11];
int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int pos = 0;
  for (int i = 0; i < s1.length(); ++i) {
    pos += s1[i] == '+' ? 1 : -1;
  }
  int pos2 = 0;
  int ukcnt = 0;
  for (int i = 0; i < s2.length(); ++i) {
    if (s2[i] == '+') {
      pos2++;
    } else if (s2[i] == '-') {
      pos2--;
    } else {
      ukcnt++;
    }
  }
  if (ukcnt == 0) {
    if (pos2 == pos)
      printf("%.12f", 1.0);
    else
      printf("%.12f", 0.0);
    return 0;
  }
  if (ukcnt < abs(pos - pos2)) {
    printf("%.12f", 0.0);
    return 0;
  }
  int lack = abs(pos - pos2);
  for (int i = 0; i <= ukcnt; ++i) {
    c[i][0] = 1;
    c[i][i] = 1;
  }

  for (int i = 1; i <= ukcnt; ++i) {
    for (int j = 1; j <= ukcnt; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  if ((ukcnt + lack) % 2 || (ukcnt - lack) % 2) {

    printf("%.12f", 0.0);
    return 0;
  }
  db ans = 1.0;
  int choose = (ukcnt + lack) >> 1;
  // cout << "ch" << c[ukcnt][choose];

  printf("%.12f", ans);

  return 0;
}
