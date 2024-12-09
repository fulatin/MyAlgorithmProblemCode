#include <bits/stdc++.h>

using namespace std;

int t;

void solve() {
  int n, k;
  cin >> n >> k;
  int gcnt = 0;
  int have = 0;
  while (n--) {
    int a;
    cin >> a;
    if (a >= k)
      have += a;
    if (a == 0 && have > 0) {
      have--;
      gcnt++;
    }
  }
  cout << gcnt << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
