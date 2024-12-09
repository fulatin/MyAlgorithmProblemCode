#include <bitset>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
struct ms {
  int pos;
  int color;
};

vector<vector<struct ms>> ls;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  ls.resize(k + 2);
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    ls[1].push_back({i, c});
  }
  for (int i = 1; i <= k; ++i) {
    int x, l, r;
    cin >> x >> l >> r;
    set<int> colors;
    set<int> needdel;
    int diffs = 0;
    int nowcolor = -1;
    for (int j = 0; j < ls[x].size(); ++j) {
      auto e = ls[x][j];
      if (e.pos >= l && e.pos <= r) {
        needdel.insert(-j);
        colors.insert(e.color);
        ls[i + 1].push_back({e.pos, e.color});
        if (nowcolor != e.color) {
          nowcolor = e.color;
          diffs++;
        }
      }
    }
    cout << colors.size() << ' ' << diffs << endl;
    for (auto e : needdel) {
      ls[x].erase(ls[x].begin() - e);
    }
  }
}
