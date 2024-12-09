#include <bits/stdc++.h>

using namespace std;

int n;

struct dat {
  int v;
  int id;
  bool operator<(dat o) { return o.v < this->v; }
};

vector<dat> arr;
bitset<300003> vis;
int main() {
  cin >> n;
  vector<int> pre(n + 2);
  vector<int> nxt(n + 2);
  pre[n + 1] = n;
  nxt[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pre[i] = i - 1;
    nxt[i] = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    int curr;
    cin >> curr;
    arr.push_back({curr, i});
  }
  sort(arr.rbegin(), arr.rend());

  int ans = 1000000000;
  for (int i = 0; i < n - 1; ++i) {

    int pos = arr[i].id;
    nxt[pos] = nxt[pos + 1];
    pre[pos + 2] = pre[pos + 1];
    int v = arr[i].v;
    int frac = max(pos + 1 - nxt[0], pre[n + 1] - (pos + 1));
    ans = min(ans, v / frac);
  }
  cout << ans << endl;
}
