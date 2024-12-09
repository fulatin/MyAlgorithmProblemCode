#include <iostream>

using namespace std;

#define MAXN 200003

int t, q, n;
int arr[MAXN];
int st[5 * MAXN];

inline int lt(int p) { return p << 1; };
inline int rt(int p) { return (p << 1) + 1; }

void build(int p, int l, int r) {
  if (l == r) {
    st[p] = arr[l] % 2;
    return;
  }

  int mid = (l + r) >> 1;
  build(lt(p), l, mid);
  build(rt(p), mid + 1, r);
  st[p] = (st[lt(p)] + st[rt(p)]) % 2;
}

int qury(int p, int l, int r, int kl, int kr, int k) {
  if (l >= kl && r <= kr) {
    return ((r - l + 1) * k) % 2;
  }
  if (r < kl || l > kr) {
    return st[p];
  }

  int mid = (l + r) >> 1;
  return (qury(lt(p), l, mid, kl, kr, k) + qury(rt(p), mid + 1, r, kl, kr, k)) %
         2;
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  build(1, 1, n);
  while (q--) {
    int tr, tl, k;
    cin >> tl >> tr >> k;
    if (qury(1, 1, n, tl, tr, k))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
