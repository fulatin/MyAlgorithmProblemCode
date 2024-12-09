#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 1;
    int now1 = 1;
    while (now1 < n) {
      now1 = 2 * (now1 + 1);
      cnt++;
    }
    cout << cnt << endl;
  }
}
