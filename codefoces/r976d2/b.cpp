
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int t;
const int MAXN = 1000000000 + 2;

int a[MAXN];
void solve() {
  memset(a, 1, (t + 1) * sizeof(int));
  for (int i = 1; i <= t; ++i) {
    for (int j = 1; j * i <= t; ++j) {
      a[i * j] = a[i * j] ? 0 : 1;
    }
    for (int j = 1; j <= t; ++j) {
      cout << a[j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  cin >> t;
  solve();
}
