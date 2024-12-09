#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 3;

long long n, k, logs[MAXN];

int check(long long l) {
  long long s = 0;
  for (int i = 1; i <= n; ++i) {
    s += logs[i] / l;
    if (s >= k)
      return 1;
  }
  return 0;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> logs[i];
  }
  long long l = 0, r = 1e8;
  while (r - l > 1) {
    long long mid = (l + r) >> 1;
    if (mid == 0) {
      cout << 0;
      return 0;
    };
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  if (l == 0) {
    cout << 0 << endl;
    return 0;
  }
  cout << (check(r) ? r : l) << endl;
}
