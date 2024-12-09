#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL mod = 1000000007;
const int MAXN = 200004;
int n[MAXN], k[MAXN];
LL dp[MAXN];
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int tn;
    cin >> tn;
    n[i] = tn;
  }
  for (int i = 0; i < t; ++i) {
    int tk;
    cin >> tk;
    k[i] = tk;
  }
  dp[0] = 1;

  for (int i = 1; i < MAXN; ++i) {
    dp[i] = (dp[i - 1] * 2) % mod;
  }
  for (int i = 0; i < t; ++i) {
    if (n[i] == k[i]) {
      cout << 1 << endl;
    } else {
      cout << dp[k[i]] << endl;
    }
  }
  return 0;
}
