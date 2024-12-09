#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 4 * 1e5 + 3;
vector<int> pre(MAXN, -1);

void dopre() {
  for (int i = 2; i < MAXN; ++i) {
    if (pre[i] == -1) {
      pre[i] = i;
      for (int j = 2; i * j < MAXN; ++j) {
        if (pre[i * j] == -1)
          pre[i * j] = i;
      }
    }
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  int pcnt = 0;
  int pval = 0;
  for (int i = 0; i < n; ++i) {
    if (pre[arr[i]] == arr[i]) {
      pcnt++;
      pval = arr[i];
    }
    if (pcnt >= 2) {
      cout << -1 << endl;
      return;
    }
  }
  if (pcnt == 0) {
    cout << 2 << endl;
    return;
  } else {
    bool flg = 1;
    for (int i = 0; i < n; ++i) {
      if (arr[i] == pval)
        continue;
      if (arr[i] % 2) {
        if (arr[i] - pre[arr[i]] < 2 * pval)
          flg = 0;
      } else {
        if (arr[i] < 2 * pval)
          flg = 0;
      }
    }
    if (flg)
      cout << pval << endl;
    else
      cout << -1 << endl;
  }
}
int main() {
  int T;
  cin >> T;
  dopre();
  // for (int i = 2; i <= 100; ++i)
  //   cout << pre[i] << endl;
  while (T--)
    solve();
  return 0;
}
