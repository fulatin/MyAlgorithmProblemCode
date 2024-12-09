#include <iostream>
using namespace std;

void ca() {
  int l, r, L, R, nl, nr;
  cin >> l >> r >> L >> R;
  nl = max(l, L);
  nr = min(r, R);
  if (nl >= nr) {
    cout << (nl == nr ? 2 : 1) << endl;
  } else {
    int res = nr - nl + 2;
    if (l == L)
      res -= 1;
    if (r == R)
      res -= 1;
    cout << res << endl;
  }
  return;
}

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    ca();
  }
  return 0;
}
