#include <bits/stdc++.h>

using namespace std;

int n, k, arr[25], cnt;

bool isprime(int x) {
  for (int i = 2; i * i < x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve(int c, int accum, int pos) {
  if (c == k) {
    if (isprime(accum)) {
      cnt++;
    }
    return;
  }
  if (pos > n) {
    return;
  }
  solve(c, accum, pos + 1);
  solve(c + 1, accum + arr[pos], pos + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  solve(0, 0, 1);
  cout << cnt;
}
