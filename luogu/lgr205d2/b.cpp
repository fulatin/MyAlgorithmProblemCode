#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 3;

set<int> g[MAXN];
int n, m, r;

int rd() {
  int res;
  char c = 0;
  while (!isdigit(c = getchar()))
    ;
  res = c - '0';
  while (isdigit(c = getchar())) {
    res = res * 10 + c - '0';
  }
  return res;
}
int outstack[100];
void ot(int x) {
  int *stackptr = outstack;
  while (x > 0) {
    *(stackptr++) = x % 10;
  }
  while (stackptr > outstack) {
    putchar(*(--stackptr));
  }
  return;
}

int dist[MAXN];
bool vis[MAXN];
void bfs() {
  queue<int> q;
  q.push(r);
  vis[r] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto e : g[u]) {
      if (vis[e])
        continue;
      // printf("now process %d 's son %d is %d\n", u, e, dist[u] + 1);
      dist[e] = dist[u] + 1;
      q.push(e);
      vis[e] = true;
    }
  }
}

int main() {
  n = rd();
  m = rd();
  r = rd();
  for (int i = 1; i <= m; ++i) {
    int u = rd(), v = rd();
    if (u == v)
      continue;
    g[u].insert(v);
    g[v].insert(u);
  }
  bfs();
  int q = rd();
  // printf("1 is %d", q);
  printf("I'm here!\n");
  while (q--) {
    int t = rd(), j = rd();
    cout << dist[t] << ' ' << dist[j];
    if (dist[t] > dist[j])
      printf("Jom\n");
    else
      printf("Terry\n");
  }
  return 0;
}
