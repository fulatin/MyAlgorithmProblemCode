#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL f[1001];
int main() {
  f[0] = 0;
  f[1] = 1;
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    LL cnt = 1;
    for (int j = i / 2; j >= 1; --j) {
      cnt += f[j];
    }
    f[i] = cnt;
  }
  cout << f[n];
  return 0;
}
