#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL w[21][21][21];
bool vis[21][21][21];

LL funcw(LL a, LL b, LL c) {
  if (a <= 0 || c <= 0 || b <= 0)
    return 1;
  else if (a > 20 || b > 20 || c > 20)
    return funcw(20, 20, 20);
  else if (a < b && b < c) {
    if (vis[a][b][c])
      return w[a][b][c];

    vis[a][b][c] = 1;
    return w[a][b][c] =
               funcw(a, b, c - 1) + funcw(a, b - 1, c - 1) - funcw(a, b - 1, c);
  }

  if (vis[a][b][c])
    return w[a][b][c];
  vis[a][b][c] = 1;
  return w[a][b][c] = funcw(a - 1, b, c) + funcw(a - 1, b - 1, c) +
                      funcw(a - 1, b, c - 1) - funcw(a - 1, b - 1, c - 1);
}

int main() {
  LL a, b, c;

  cin >> a >> b >> c;
  while (!(a == -1 && b == -1 && c == -1)) {
    printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, funcw(a, b, c));

    cin >> a >> b >> c;
  }
  return 0;
}
