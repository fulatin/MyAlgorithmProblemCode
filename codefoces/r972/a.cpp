#include <bits/stdc++.h>

using namespace std;

int t;

int buffer[103];
char m[] = {'a', 'e', 'i', 'o', 'u'};

void solve() {
  int n;
  cin >> n;
  vector<int> v(5, n / 5);
  for (int i = 0; i < n % 5; ++i) {
    v[i] = n / 5 + 1;
  }
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < v[i]; ++j)
      cout << m[i];
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
