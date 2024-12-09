#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

set<int> s[1002];

int cases;
int cnt, n;
bool ok[1002];
void question(int a, int b) {
  cout << "? " << a << " " << b << endl;
  cout.flush();
  int resa;
  cin >> resa;
  if (resa == a) {
    if (s[a].find(b) != s[a].end())
      return;
    ok[a] = true;
    ok[b] = true;
    s[a].insert(b);
    s[b].insert(a);
    cnt++;
    return;
  }
  cout << "? " << b << " " << a << endl;
  cout.flush();
  int resb;
  cin >> resb;
  if (resa != resb) {
    if (s[resa].find(resb) == s[resa].end()) {
      s[resa].insert(resb);
      s[resb].insert(resa);
      cnt++;
    }
  }
  if (cnt == n - 1)
    return;
  if (!ok[a] || !ok[resa])
    question(a, resa);
  if (!ok[b] || !ok[resb])
    question(resb, b);
  ok[a] = true;
  ok[b] = true;
  ok[resa] = true;
  ok[resb] = true;
}

void cs() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    s[i].clear();
  }
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    ok[i] = false;
  }
  for (int i = 2; i <= n; ++i) {
    if (!ok[i])
      question(1, i);
  }

  cout << "! ";
  cout.flush();
  for (int i = 1; i <= n; ++i) {
    for (auto e : s[i]) {
      if (i < e) {
        cout << i << ' ' << e << ' ';
        cout.flush();
      }
    }
  }
  cout << endl;
  cout.flush();
}
int main() {
  cin >> cases;
  while (cases--) {
    cs();
  }
}
