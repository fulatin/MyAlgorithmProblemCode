#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << 2 * max(a, max(b, c)) << endl;
  return 0;
}
