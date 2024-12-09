#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 2), b(n + 2);
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    a[curr] = i;
  }
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    b[curr] = i;
  }
  int mx = -1;
  vector<int> posm(n);
  for (int i = 1; i <= n; ++i) {
    posm[(a[i] - b[i] < 0 ? (a[i] - b[i] + n) : (a[i] - b[i]))]++;
  }
  for (int i = 0; i < n; ++i) {
    mx = max(mx, posm[i]);
  }
  cout << mx;
  return 0;
}
