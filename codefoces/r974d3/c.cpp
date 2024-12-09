#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int t;

vector<int> arr;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
  arr.clear();
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    sum += curr;
    arr.push_back(curr);
  }
  if (n <= 2) {
    cout << -1 << endl;
    return;
  }
  sort(arr.begin(), arr.end());
  int m = arr[n / 2];
  long long x = 2 * (long long)n * m - sum + 1ll;
  if (x < 0)
    cout << 0 << endl;
  if (x >= 0)
    cout << x << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
