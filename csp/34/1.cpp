
#include <bits/stdc++.h>

using namespace std;

int m, n, t;

vector<vector<int>> a;

void redo(int p, int q) {
  queue<int> tmp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int curr = a[i][j];
      tmp.push(curr);
    }
  }
  a.clear();
  a.resize(p);
  for (int i = 0; i < p; ++i) {
    a[i].resize(q);
  }

  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < q; ++j) {
      a[i][j] = tmp.front();
      tmp.pop();
    }
  }
  n = p;
  m = q;
}

void trans() {
  vector<vector<int>> res;
  res.resize(m);
  for (int i = 0; i < m; ++i) {
    res[i].resize(n);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      res[j][i] = a[i][j];
    }
  }
  int tmp = n;
  n = m;
  m = tmp;
  a = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> t;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    a[i].resize(m);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int curr;
      cin >> curr;
      a[i][j] = curr;
    }
  }

  while (t--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int p, q;
      cin >> p >> q;
      redo(p, q);

    } else if (tp == 2) {
      int tmp;
      cin >> tmp;
      cin >> tmp;
      trans();
    } else {
      int i, j;
      cin >> i >> j;
      cout << a[i][j] << endl;
    }
  }
}
