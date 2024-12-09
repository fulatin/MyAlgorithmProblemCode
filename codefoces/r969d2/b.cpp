#include <iostream>

using namespace std;

int t;

void solve() {
  int n, m;
  cin >> n >> m;
  int res = -1;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    res = max(res, curr);
  }
  while (m--) {
    char tp;
    int l, r;
    cin >> tp >> l >> r;
    int addvar = tp == '+' ? 1 : -1;
    if (res >= l && res <= r)
      res += addvar;
    cout << res << " ";
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
