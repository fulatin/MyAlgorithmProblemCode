#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int n, m, v, mycst = INT_MAX;
vector<int> b, c, a, t;
bool used[1002];

void solve(int now, int val, int cost) {
  if (cost >= mycst)
    return;
  if (val - cost >= v) {
    mycst = min(cost, mycst);
    return;
  }
  if (now >= m)
    return;

  solve(now + 1, val, cost);
  int inthis = false;
  if (!used[t[now]]) {

    cost += b[t[now]];
    inthis = true;
    used[t[now]] = true;
  }
  val += a[now];

  cost += c[t[now]];
  solve(now + 1, val, cost);
  if (inthis) {
    used[t[now]] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);

  cin >> n >> m >> v;
  for (int i = 0; i < n; ++i) {
    int t1, t2;
    cin >> t1 >> t2;
    b.push_back(t1);
    c.push_back(t2);
  }
  for (int i = 0; i < m; ++i) {
    int val, in;
    cin >> val >> in;
    t.push_back(in);
    a.push_back(val);
  }
  solve(0, 0, 0);
  cout << mycst;
}
