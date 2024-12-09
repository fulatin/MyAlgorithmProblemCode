#include <bits/stdc++.h>
typedef long long LL;

using namespace std;

int rd() {
  int res = 1, sign = 1;
  char c = 0;
  while (!isdigit(c = getchar())) {
    if (c == '-')
      sign = -1;
  }
  res = c - '0';
  while (isdigit(c = getchar())) {
    res = res * 10 + c - '0';
  }
  return res * sign;
}

void out(LL x) {
  int sign = 1;
  if (x < 0) {
    sign = -1;
    x = -x;
  }

  stack<int> s;
  while (x > 0) {
    s.push(x % 10);
    x /= 10;
  }
  if (sign == -1)
    putchar('-');
  while (!s.empty()) {
    putchar(s.top());
    s.pop();
  }
}

const int MAXN = 1e6 + 4;

LL n, arr[MAXN], lsm[MAXN], lmaxsm[MAXN], rsm[MAXN], rmaxsm[MAXN], lmin[MAXN],
    rmin[MAXN];

void solve() {
  n = rd();
  LL sum = 0;

  for (int i = 1; i <= n; ++i) {
    arr[i] = rd();
    sum += arr[i];
    lsm[i] = arr[i] + lsm[i - 1];
    lmaxsm[i] = lsm[i] > lsm[lmaxsm[i - 1]] ? i : lmaxsm[i - 1];
  }
  rmaxsm[n + 1] = n + 1;
  rsm[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    rsm[i] = arr[i] + rsm[i + 1];
    rmaxsm[i] = rsm[i] > rsm[rmaxsm[i + 1]] ? i : rmaxsm[i + 1];
  }
  lmin[1] = arr[1];
  for (int i = 2; i <= n; ++i) {
    lmin[i] = min(arr[i], lmin[i - 1]);
  }
  rmin[n] = arr[n];
  for (int i = n - 1; i >= 1; i--) {
    rmin[i] = min(arr[i], rmin[i - 1]);
  }
  LL ans = -1e18;
  // for (int i = 1; i <= n; ++i) {
  //   ans = max(ans, sum - 2 * (lsm[i] - lmaxsm[i]));
  //   cout << ans << endl;
  // }
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sum - 2 * (lsm[i] - lsm[lmaxsm[i - 1]]));
    // cout << ans << endl;
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << lsm[i] << ' ';
  // }
  // cout << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << rsm[i] << ' ';
  // }
  // cout << endl;
  for (int i = 2; i <= n - 1; ++i) {
    int l = lmaxsm[i - 1];
    int r = rmaxsm[i + 1];
    // printf("%d %d %d \n", i, l, r);
    if (l < 1 && r > n) {
      ans =
          max(ans, sum - 2 * (lsm[i - 1] - lsm[l]) - 2 * (rsm[i + 1] - rsm[r]));
      continue;
    }
    LL exchange = 1e17;
    if (l >= 1)
      exchange = lmin[l];
    if (r <= n)
      exchange = min(exchange, rmin[r]);
    ans = max(ans, sum - 2 * exchange - 2 * (lsm[i - 1] - lsm[l]) -
                       2 * (rsm[i + 1] - rsm[r]));
    // cout << ans << endl;
  }
  out(ans);
  putchar('\n');
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    solve();
}
