#include <bits/stdc++.h>

using namespace std;

int m, n, p, q;

vector<vector<int>> a;

queue<int> tmp;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> p >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int curr;
      cin >> curr;
      tmp.push(curr);
    }
  }
  int cnt = 0;
  for (int i = 0; i < m * n; ++i) {
    int a = tmp.front();
    tmp.pop();
    cout << a << " ";
    if (++cnt >= q) {
      cnt = 0;
      cout << endl;
    }
  }
  return 0;
}
