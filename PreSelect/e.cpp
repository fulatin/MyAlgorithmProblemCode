#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 101;
int arr[MAXN][MAXN];
int t, n;

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    memset(arr[i], 0, sizeof(arr[0]));
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      arr[i][j] = s[j] - '0';
    }
  }
  int cnt = 0;
  int end1 = (n - 1) / 2;
  int end2 = end1 - (n % 2 ? 1 : 0);
  for (int i = 0; i <= end1; ++i) {
    for (int j = 0; j <= end2; ++j) {
      int zcnt = 0;
      int ocnt = 0;
      int cpi = i;
      int cpj = j;
      for (int k = 1; k <= 4; ++k) {
        int tmp = cpj;
        cpj = n - 1 - cpi;
        cpi = tmp;
        if (arr[cpi][cpj] == 1) {
          ocnt++;
        } else {
          zcnt++;
        }
      }
      cnt += 4 - max(zcnt, ocnt);
    }
  }
  cout << cnt << endl;
  ;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
    solve();
}
