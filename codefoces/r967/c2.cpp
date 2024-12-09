
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

set<int> s[1002];

int cases;
int cnt, n;
bool ok[1002][1002];
void bfs(int i) {
  for (int j = 1; j <= n; ++j) {
    ok[i][j] = false;
  }
  queue<int> q;
  q.push(i);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    if (!ok[i][a]) {
      ok[i][a] = true;
      for (int e : s[a]) {
        q.push(e);
      }
    }
  }
}
void question(int a, int b, bool odd = false) {
  cout << "? " << a << " " << b << endl;
  cout.flush();
  int resa;
  cin >> resa;
  if (resa == a) {
    if (s[a].find(b) != s[a].end())
      return;
    s[a].insert(b);
    s[b].insert(a);
    cnt++;
    return;
  }
  int resb;
  if (odd) {
    resb = resa;
  } else {
    cout << "? " << b << " " << a << endl;
    cout.flush();
    cin >> resb;
  }

  if (resa != resb) {
    if (s[resa].find(resb) == s[resa].end()) {
      s[resa].insert(resb);
      s[resb].insert(resa);
      cnt++;
    }
  }
  odd = true;

  if (cnt == n - 1)
    return;
  question(a, resa, odd);
  question(resb, b, odd);
}

void cs() {
  cin >> n;
  cout.flush();
  for (int i = 1; i <= n; ++i) {
    s[i].clear();
  }
  cnt = 0;

  for (int i = 1; i < n; ++i) {
    bfs(i);
    for (int j = 2; j <= n; ++j) {
      if (!ok[i][j]) {
        question(i, j);
        bfs(i);
        if (cnt == n - 1) {
          cout << "! ";
          for (int k = 1; k <= n; ++k) {
            for (int e : s[k]) {
              if (k < e) {
                cout << k << " " << e << " ";
              }
            }
          }
          cout << endl;
          cout.flush();
          return;
        }
      }
    }
  }
}
int main() {
  cin >> cases;
  cout.flush();
  while (cases--) {
    cs();
  }
}
