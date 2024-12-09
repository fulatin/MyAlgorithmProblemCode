#include <bits/stdc++.h>

using namespace std;

int f[20];
int n;
int main() {
  cin >> n;
  f[1] = 1;
  f[0] = 1;
  for (int i = 2; i <= n; ++i) {
    int tmp = 0;
    for (int j = 1; j <= i; ++j) {
      tmp += f[j - 1] * f[i - j];
    }
    f[i] = tmp;
  }
  cout << f[n];
  return 0;
}
