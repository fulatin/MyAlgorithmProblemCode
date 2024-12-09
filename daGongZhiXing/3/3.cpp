#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
  cin >> n >> t;
  vector<int> l;
  vector<int> r;
  for (int i = 1; i <= n; ++i) {
    int tp, val;
    cin >> tp >> val;
    if (tp == 1)
      r.push_back(val);
    else
      l.push_back(val);
  }
  sort(l.begin(), l.end());
  vector<int> lrequire(l.size() + 1);
  for (int i = 0; i < l.size(); ++i) {
    lrequire[i + 1] = l[i];
  }
  int maxans = 0;
  sort(r.begin(), r.end());
  for (int i = 0; i < r.size(); ++i) {
    int used = r[i];
    if (2 * used > t)
      break;
    auto upperpos = upper_bound(lrequire.begin(), lrequire.end(), t - 2 * used);
    maxans = max(maxans, i + 1 + (int)(upperpos - lrequire.begin()) - 1);
  }
  int maxans2 = (int)(upper_bound(lrequire.begin() + 1,
                                  lrequire.begin() + lrequire.size(), t) -
                      lrequire.begin()) -
                1;
  cout << max(maxans, maxans2) << endl;
}
