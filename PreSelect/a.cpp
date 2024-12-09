#include <bits/stdc++.h>

using namespace std;

int n, h;

int main() {
  cin >> n >> h;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    if (curr > h) {
      ans += 2;
    } else {
      ans += 1;
    }
  }
  cout << ans;
  return 0;
}
