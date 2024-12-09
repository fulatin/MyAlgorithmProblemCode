#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 10;
const string t1 = "YA";
const string t2 = "TIDAK";
int ls[N];
int nx[N];
int b[N];
vector<set<int>> idx(N + 2);
int fir(int x) {
  int t;
  t = *idx[x].begin();
  return t;
}
void solve() {
  // 使用set存放所有bi的i，在更新bi的时候我们可以更新不合法的顺序，当不合法的顺序为0时即为合法
  int n, m, q;
  cin >> n >> m >> q;
  int t1, t2 = 1;
  cin >> t1;
  ls[t1] = 0;
  for (int i = 2; i <= n; i++) {
    cin >> t2;
    ls[t2] = t1;
    nx[t1] = t2;
    t1 = t2;
  }
  nx[t2] = n + 1;
  for (int i = 0; i <= n + 1; i++) {
    idx[i].clear();
  }
  idx[0].insert(0);
  idx[n + 1].insert(1000000);
  for (int i = 1; i <= n; i++) {
    idx[i].insert(1000000);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    idx[b[i]].insert(i);
  }
  int f = 0;
  for (int i = 1; i <= n; i++) {
    if (fir(ls[i]) > fir(i))
      f++;
  }
  if (f == 0) {
    cout << "YA" << endl;
  } else
    cout << "TIDAK" << endl;
  for (int i = 1; i <= q; i++) {
    int s, t;
    cin >> s >> t;
    if (fir(b[s]) == s) {
      // 对于将一个数字改变会发生什么影响呢，
      // 删除这个数的影响，加入b[s]下一个的影响
      // 删除第一个t的影响，加入新的t的影响
      if (fir(ls[b[s]]) > fir(b[s]))
        f--;
      if (fir(nx[b[s]]) < fir(b[s]))
        f--;
      idx[b[s]].erase(s);
      if (fir(ls[b[s]]) > fir(b[s]))
        f++;
      if (fir(nx[b[s]]) < fir(b[s]))
        f++;
    } else
      idx[b[s]].erase(s);

    if (fir(t) > s) {
      if (fir(t) < fir(ls[t]))
        f--;
      if (fir(t) > fir(nx[t]))
        f--;
      idx[t].insert(s);
      if (fir(t) < fir(ls[t]))
        f++;
      if (fir(t) > fir(nx[t]))
        f++;
    } else
      idx[t].insert(s);
    b[s] = t;
    if (f == 0) {
      cout << "YA" << endl;
    } else
      cout << "TIDAK" << endl;
  }
}
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
