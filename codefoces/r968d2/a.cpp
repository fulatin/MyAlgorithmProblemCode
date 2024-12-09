#include <iostream>

using namespace std;

int t;

char s[103];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 1; i < n; ++i) {
    if (s[1] != s[n] && s[i] != s[i + 1]) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  cin >> t;
  while (t--)
    solve();
}
