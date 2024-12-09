
#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  cin >> n;
  if (n == 1) {
    cout << -1;
    return 0;
  }
  if (n == 2) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << -1;
      return 0;
    } else {
      cout << 1 << endl;
      cout << 1;
      return 0;
    }
  }
  int sum = 0;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
  }
  if (v[0] == sum - v[0]) {
    cout << 2 << endl;
    cout << 1 << ' ' << 2 << endl;
  } else {
    cout << 1 << endl;
    cout << 1;
  }
  return 0;
}
