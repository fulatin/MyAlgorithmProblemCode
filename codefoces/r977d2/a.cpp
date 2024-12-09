#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>

using namespace std;
int MAXI = 0x3fffffff;
int t;
void solve() {
  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> a;
  for (int i = 0; i < n; ++i) {
    int curr;
    cin >> curr;
    a.push(curr);
  }
  for (int i = 1; i <= n - 1; ++i) {
    int x1 = a.top();
    a.pop();
    int x2 = a.top();
    a.pop();
    a.push((x1 + x2) >> 1);
  }
  cout << a.top() << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
