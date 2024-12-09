
#include <bits/stdc++.h>

using namespace std;
string s;
int main() {
  cin >> s;
  int n = s.size();
  string a;
  string b;
  for (int i = 0; i <= n / 2; ++i) {
    a = a + s[i];
    b = s[n - 1 - i] + b;
    if (a == b) {
      int j;
      for (j = 0; j < n; ++j) {
        if (a[j % a.size()] != s[j])
          break;
      }
      if (j == n) {
        cout << s.size() / a.size();
        return 0;
      }
    }
  }
  return 0;
}
