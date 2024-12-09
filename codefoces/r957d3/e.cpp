#include <bits/stdc++.h>

using namespace std;
int t, n;
int arr[5];
int ncnt(int s) {
  int cnt = 0;
  while (s > 0) {
    s /= 10;
    cnt++;
  }
  return cnt;
}

void toarr() {
  int cpn = n;
  int nn = ncnt(n);
  for (int i = nn; i >= 1; i--) {
    arr[i] = cpn % 10;
    cpn /= 10;
  }
}
void solve() {
  cin >> n;
  int nn = ncnt(n);
  toarr();
  queue<int> ansa;
  queue<int> ansb;
  int totl = 0;
  for (int a = 1; a <= 10000; ++a) {

    for (int b = max(1, nn * a - 5); b <= min(10000, nn * a); ++b) {
      if (a * n - b == 0)
        continue;
      if (a * nn - b != ncnt(a * n - b))
        continue;
      int target = a * n - b;
      int ntar = ncnt(target);
      int spos = ntar % nn;
      bool ok = true;
      while (target > 0) {
        if (spos == 0)
          spos = nn;
        if (arr[spos] != target % 10) {
          ok = false;
          break;
        }
        spos--;
        target /= 10;
      }
      if (ok) {
        totl++;
        ansa.push(a);
        ansb.push(b);
      }
    }
  }
  cout << totl << endl;
  while (!ansa.empty()) {
    cout << ansa.front() << " " << ansb.front() << endl;
    ansa.pop();
    ansb.pop();
  }
}
int main() {
  cin >> t;
  while (t--)
    solve();
}
