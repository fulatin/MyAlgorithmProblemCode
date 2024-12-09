#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int t;

vector<int> arr;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve() {
  arr.clear();
  int n, a, b;
  cin >> n >> a >> b;
  int gap = gcd(a, b);
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    arr.push_back(curr % gap);
  }
  if (gap == 1) {
    cout << 0 << endl;
    return;
  }
  sort(arr.begin(), arr.end());
  int res = arr[n - 1] - arr[0];
  for (int i = 1; i < n; ++i) {
    res = min(res, arr[i - 1] + gap - arr[i]);
  }
  cout << res << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
