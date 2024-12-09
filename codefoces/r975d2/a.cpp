#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int t, n, ans;

struct d {
  int val;
  int pos;
  bool operator<(struct d o) { return o.val < this->val; };
};
vector<struct d> arr;

void solve() {
  arr.clear();
  ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    arr.push_back({curr, i});
  }
  sort(arr.begin(), arr.end());

  if (n % 2 == 0) {
    cout << arr[0].val + n / 2 << endl;
  } else {
    int m = -1;
    for (int i = 0; i < n; ++i) {
      struct d ms = arr[i];
      m = max(m, (ms.pos % 2) ? (ms.val + (n + 1) / 2) : (ms.val + n / 2));
    }
    cout << m << endl;
    ;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
    solve();
}
