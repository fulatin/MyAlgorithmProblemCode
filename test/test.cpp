
#include <bits/stdc++.h>
#include <string>
using namespace std;

int b[10005][10005] = {0};
int a[10005][10005] = {0};
int dirx[] = {0, 1, 0, -1};
int diry[] = {1, 0, -1, 0};
void key() {
  long long n, m, k, x, y, d;
  char c;
  //	memeset(a,sizeof(a),0);
  //	memeset(b,sizeof(b),0);
  cin >> n >> m >> k;
  cin >> x >> y >> d;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      b[i][j] = 0;
      cin >> c;
      if (c == '.')
        a[i][j] = 1;
      else if (c == 'x')
        a[i][j] = 0;
    }
  }

  b[x][y] = 1;
  for (int i = 1; i <= k; ++i) {
    int nx = x + dirx[d];
    int ny = y + diry[d];
    if (nx <= 0 || ny <= 0 || nx > n || ny > m || a[nx][ny] == 0) {
      d = (d + 1) % 4;
      continue;
    }
    b[nx][ny] = 1;
    x = nx;
    y = ny;
  }
  long long cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cnt += b[i][j];
    }
  }
  cout << cnt << endl;
  return;
}

int main() {
  long long t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    key();
  }
  return 0;
}
