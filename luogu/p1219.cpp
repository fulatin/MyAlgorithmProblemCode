#include <bits/stdc++.h>

using namespace std;

int n;

int anscnt, cnt;

bool col[20], dig1[100], dig2[100];
int tmpans[100];
void taken(int x, int y) {
  col[y] = true;
  dig1[x + y] = true;
  dig2[x - y + n] = true;
}

void release(int x, int y) {
  col[y] = false;
  dig1[x + y] = false;
  dig2[x - y + n] = false;
}

bool ok(int x, int y) { return !col[y] && !dig1[x + y] && !dig2[x - y + n]; }
void search(int x) {
  if (x > n) {
    anscnt++;
    if (anscnt > 3)
      return;
    for (int i = 1; i <= n; ++i) {
      cout << tmpans[i] << ' ';
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (ok(x, i)) {
      taken(x, i);
      tmpans[x] = i;
      search(x + 1);
      release(x, i);
    }
  }
}

int main() {
  cin >> n;
  search(1);
  cout << anscnt;
}
