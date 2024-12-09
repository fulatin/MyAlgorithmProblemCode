#include <bits/stdc++.h>
#include <cstring>

using namespace std;
const int MAXN = 200000;
int n, q;
int contmp[MAXN + 2];

int con[MAXN + 2];
char s[MAXN + 3];
void solve() {

  scanf("%d%d", &n, &q);

  memset(con, 0, (n) * sizeof(int));
  memset(contmp, 0, (n) * sizeof(int));
  for (int i = 0; i < n; ++i) {
    int curr, perm;
    scanf("%d", &curr);
    perm = curr - 1;
    if (perm > i) {
      contmp[i]++;
      contmp[perm]--;
    } else if (perm < i) {
      contmp[perm]++;
      contmp[i]--;
    }
    // for (int i = 0; i < n; ++i) {
    // cout << contmp[i] << ' ';
    // }
    // cout << endl;
  }
  con[0] = contmp[0];

  for (int i = 1; i < n; ++i) {
    con[i] = con[i - 1] + contmp[i];
    // cout << con[i] << ' ';
  }
  // cout << endl;
  scanf("%s", s);

  int bad = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'L' && s[i + 1] == 'R' && con[i])
      bad++;
  }
  while (q--) {
    int pos;
    cin >> pos;
    char posc = s[pos - 1];
    if (pos == 1) {
      if (posc == 'L' && con[0])
        bad--;
      else if (posc == 'R' && con[0])
        bad++;
    } else if (pos == n) {
      if (posc == 'R' && con[n - 2])
        bad--;
      else if (posc == 'L' && con[n - 2])
        bad++;
    } else {
      char pposc = s[pos - 2];
      char lposc = s[pos];
      if (posc == 'L') {
        if (pposc == 'L' && con[pos - 2])
          bad++;
        // if(pposc=='R'&&con[pos-2]) bad--;
        // if(lposc=='L'&&con[pos-1]) bad++;
        if (lposc == 'R' && con[pos - 1])
          bad--;
      } else {
        if (pposc == 'L' && con[pos - 2])
          bad--;
        // if(pposc=='R')
        // if(lposc=='L'&&con[pos-1]) bad
        if (lposc == 'R' && con[pos - 1])
          bad++;
      }
    }
    s[pos - 1] = posc == 'L' ? 'R' : 'L';
    if (bad == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
