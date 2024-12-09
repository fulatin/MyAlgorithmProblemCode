

#include <bits/stdc++.h>

using namespace std;
long long t;

int ncnt(int x) {
  int cnt = 0;
  while (x > 0) {
    cnt++;
    x /= 10;
  }
  return cnt;
}

void solve() {
  int x1, x2, p1, p2;
  cin >> x1 >> p1;
  cin >> x2 >> p2;
  if (ncnt(x1) + p1 > ncnt(x2) + p2) {
    cout << ">" << endl;
  } else if (ncnt(x1) + p1 < ncnt(x2) + p2) {
    cout << "<" << endl;
  } else {
    int nx1 = ncnt(x1);
    int nx2 = ncnt(x2);
    if (nx1 > nx2) {
      for (int i = 1; i <= nx1 - nx2; i++) {
        x2 *= 10;
      }
    } else if (nx1 < nx2) {
      for (int i = 1; i <= nx2 - nx1; i++) {
        x1 *= 10;
      }
    }
    if (x1 < x2)
      cout << "<" << endl;
    else if (x1 > x2)
      cout << ">" << endl;
    else
      cout << "=" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
    solve();
  return 0;
}
