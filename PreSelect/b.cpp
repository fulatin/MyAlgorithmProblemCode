
#include <bits/stdc++.h>

using namespace std;
long long t;

void solve() {
  long long n;
  cin >> n;
  long long cnt = 0;
  long long m = 1;

  long long cpn = n;
  while (cpn > 0) {
    cpn /= 10;
    m *= 10;
  }
  cout << n - m / 10 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
    solve();
  return 0;
}
