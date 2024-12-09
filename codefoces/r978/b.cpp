#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
int t;
void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {

    cin >> arr[i];
  }
  vector<int> mark(x, 0);
  long long cnt = 0;
  while (arr.size() > x) {
    cnt++;
    sort(arr.begin(), arr.end(), greater<>());

    for (int i = 0; i < x; ++i) {
      arr[i]--;
      if (arr[i] == 0)
        mark[i] = 1;
    }
    for (int i = x - 1; i >= 0; i--)
      if (mark[i])
        arr.erase(arr.begin() + i);
    cout << "start:";
    for (int e : arr)
      cout << e << " ";
    cout << endl;
  }

  sort(arr.begin(), arr.end(), greater<>());
  cnt += arr[0];
  // cout << "ans:" << cnt << endl;
  cout << cnt << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
