#include <bits/stdc++.h>

using namespace std;

int n;

void solve() {
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  int score = 0;
  vector<int> maxpre(n + 1);
  for (int i = 1; i <= n; i++) {
    if (arr[i] > score)
      score++;
    else if (arr[i] < score)
      score--;
    maxpre[i] = max(maxpre[i - 1], score);
  }
  auto check = [&](int x) {
    for (int i = n; i >= 1; --i) {
      if (maxpre[i - 1] >= x)
        return true;
      if (arr[i] >= x)
        x--;
      else if (arr[i] < x)
        x++;
    }
    return false;
  };
  int l = 1, r = n;
  while (l <= r) {
    // cout << l << ' ' << r << endl;
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << r << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
