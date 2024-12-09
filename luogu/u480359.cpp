#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000000;
typedef long long ll;
int t;
void solve() {
  ll n, m;
  cin >> n >> m;
  int cnt2 = 0, cnt5 = 0;
  ll cp = n;
  while ((cp % 5) == 0 || (cp % 2) == 0) {
    if (cp % 5 == 0) {
      cp /= 5;
      cnt5++;
    }
    if (cp % 2 == 0) {
      cp /= 2;
      cnt2++;
    }
  }
  long long k = 1;
  while (true) {

    if (cnt2 == cnt5) {
      if (k * 10ll > m) {
        break;
      } else {
        k *= 10ll;
      }
    }
    if (cnt2 < cnt5) {
      if (k * 2ll > m) {
        break;
      } else {
        cnt2++;
        k *= 2ll;
      }
    }
    if (cnt2 > cnt5) {
      if (k * 5ll > m) {
        break;
      } else {
        cnt5++;
        k *= 5ll;
      }
    }
  }

  for (int i = 10; i >= 1; --i) {
    if (k * i <= m) {
      k *= i;
      break;
    }
  }
  cout << k * n << endl;
}
int main() {
  ios::sync_with_stdio(false);

  cin >> t;
  while (t--)
    solve();
}
