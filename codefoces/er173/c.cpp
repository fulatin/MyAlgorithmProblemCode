#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

pair<int, int> maxGap(vector<int> a) {
  int maxs = a[a.size() - 1];
  int mins = a[a.size() - 1];
  vector<int> maxv(a.size()), minv(a.size());
  for (int i = a.size() - 1; i >= 1; i--) {
    if (a[i] < mins) {
      mins = a[i];
    }
    if (a[i] > maxs) {
      maxs = a[i];
    }
    maxv[i] = maxs;
    minv[i] = mins;
  }
  int mingap = 0x3fffffff;
  int maxgap = -0x3fffffff;
  for (int i = 1; i <= a.size() - 1; ++i) {
    mingap = min(mingap, minv[i] - a[i]);
    maxgap = max(maxgap, maxv[i] - a[i]);
  }
  return {mingap, maxgap};
}

void solve() {
  int n;
  cin >> n;
  int bpos = n / 2;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    if (arr[i] != 1 || arr[i] != -1) {
      bpos = i;
    }
  }
  int spval = arr[bpos];
  vector<int> larr(bpos);
  vector<int> rarr(n - bpos + 1);
  for (int i = 1; i < bpos; ++i) {
    larr[i] = arr[i] + larr[i - 1];
  }
  for (int i = bpos + 1; i <= n; ++i) {
    rarr[i - bpos] = arr[i] + rarr[i - bpos - 1];
  }
  set<int> ans;
  auto [min1, max1] = maxGap(larr);
  auto [min2, max2] = maxGap(rarr);
  for (int i = min1; i <= max1; ++i) {
    ans.insert(i);
  }
  for (int i = min2; i <= max2; ++i) {
    ans.insert(i);
  }
  int lmax = -0x3fffffff;
  int lmin = 0x3fffffff;
  int rmax = -0x3fffffff;
  int rmin = 0x3fffffff;
  int lsum = 0;
  for (int i = bpos - 1; i >= 1; i--) {
    lsum += arr[i];
    lmax = max(lsum, lmax);
    lmin = min(lmin, lsum);
  }
  int rsum = 0;
  for (int i = bpos + 1; i <= n; ++i) {
    rsum += arr[i];
    rmax = max(rmax, rsum);
    rmin = min(rmin, rsum);
  }
  int lbound = arr[bpos] + lmin + rmin;
  int rbound = arr[bpos] + lmax + rmax;
  for (int i = lbound; i <= rbound; ++i) {
    ans.insert(i);
  }
  cout << ans.size() << endl;
  for (auto e : ans) {
    cout << e << ' ';
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
