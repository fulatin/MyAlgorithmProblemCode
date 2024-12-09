#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
  int n;
  cin >> n;
  long long ans = 10e18 + 1;
  auto func = [&](vector<long long> a) {
    long long res = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); ++i)
      if (a[i] == a[i - 1])
        return;

    for (int i = 0; i < a.size() - 1; i += 2) {
      res = max(res, abs(a[i] - a[i + 1]));
    }
    ans = min(ans, res);
  };
  vector<long long> arr(n);
  for (auto &e : arr)
    cin >> e;
  if (n % 2 == 0) {
    func(arr);
    cout << ans << endl;
  } else {
    for (int i = 0; i <= n; ++i) {
      for (auto x : {-1, 1}) {
        arr.push_back(arr[i] + x);
        func(arr);
        arr.pop_back();
      }
    }
    cout << ans << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
