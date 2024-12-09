#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100004;

int arr[MAXN];
int t, n;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  if (n == 2) {
    cout << (arr[1] == arr[2]) << endl;
    return;
  }
  int dist = 0;
  for (int i = 2; i <= n / 2; ++i) {
    if (arr[i] == arr[i - 1] || arr[n - i + 1] == arr[n - i + 2]) {
      int tmp = arr[i];
      arr[i] = arr[n - i + 1];
      arr[n - i + 1] = tmp;
    }
    if (arr[i] == arr[i - 1])
      dist++;
    if (arr[n - i + 1] == arr[n - i + 2])
      dist++;
  }
  if (n % 2) {
    if (arr[n / 2] == arr[n / 2 + 1])
      dist++;
    if (arr[n / 2 + 1] == arr[n / 2 + 2])
      dist++;
  } else {
    if (arr[n / 2] == arr[n / 2 + 1])
      dist++;
  }
  cout << dist << endl;
}

int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
