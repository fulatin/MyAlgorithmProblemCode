#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int MOD = 1000;

vector<int> dp(1e7 + 2, -1);

int main() {
  long long n;
  cin >> n;
  dp[1] = 1;
  dp[2] = 1;
  int nowhas = 2;
  set<int> ans;
  for (int i = 1; i <= n; ++i) {
    int a;
    a = i;
    if (a > nowhas) {
      for (int j = nowhas + 1; j <= a; ++j) {
        dp[j] = (dp[j - 1] + dp[j - 2]) % MOD;
      }
      nowhas = a;
      ans.insert(dp[a]);
    }
    cout << dp[a] << endl;
  }
  for (int e : ans) {
    cout << e << endl;
  }
  return 0;
}
