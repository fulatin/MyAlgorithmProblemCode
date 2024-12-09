#include <bits/stdc++.h>

typedef long long LL;
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int res = a - b;
  if (a - b < 0)
    cout << 0;
  else
    cout << res;
}
