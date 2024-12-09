#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  long long n;
  cin >> s;
  cin >> n;
  int len = s.size();
  long long contain = len;
  while (contain < n)
    contain *= 2;
  while (n > s.size()) {
    if (n <= contain / 2) {
      contain /= 2;
      continue;
    }
    if (n == contain / 2 + 1ll)
      n = contain / 2;
    else
      n = n - contain / 2 - 1;
    contain /= 2;
  }
  cout << s[n - 1];
}
