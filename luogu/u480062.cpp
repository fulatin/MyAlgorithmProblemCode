#include <bits/stdc++.h>

using namespace std;

struct edge {
  bool exist;
  int to;
};

vector<struct edge> p[1003];

int n;
stack<int> ans;

void solve(int a) {
  for (int i = 0; i < p[a].size(); ++i) {
    struct edge &e = p[a][i];
    if (e.exist) {

      e.exist = false;
      solve(e.to);
    }
  }
  ans.push(a);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j == i)
        continue;
      p[i].push_back({1, j});
    }
  }

  solve(1);

  while (!ans.empty()) {
    int ele = ans.top();
    ans.pop();
    cout << ele << ' ';
  }
}
