#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  int ld = 0;
  while (ld * (ld + 1) <= 2 * t) {
    ld++;
  };
  ld--;
  int ans = 0;
  for (int i = 1; i <= ld; ++i) {
    ans += i * i;
  }
  for (int i = 1; i <= t - ((ld + 1) * ld) / 2; ++i) {
    ans += ld + 1;
  }
  cout << ans;
}
