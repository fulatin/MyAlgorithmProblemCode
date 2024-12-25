#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

pair<long long, long long> maxGap(vector<long long> a) {
  long long maxs = a[a.size() - 1];
  long long mins = a[a.size() - 1];
  vector<long long> maxv(a.size()), minv(a.size());
  for (long long i = a.size() - 1; i >= 0; i--) {
    if (a[i] < mins) {
      mins = a[i];
    }
    if (a[i] > maxs) {
      maxs = a[i];
    }
    maxv[i] = maxs;
    minv[i] = mins;
  }
  long long mingap = 0;
  long long maxgap = 0;
  for (long long i = 0; i <= a.size() - 1; ++i) {
    mingap = min(mingap, minv[i] - a[i]);
    maxgap = max(maxgap, maxv[i] - a[i]);
  }
  return {mingap, maxgap};
}

void solve() {
  long long n;
  cin >> n;
  long long bpos = (n + 1) / 2;
  vector<long long> arr(n + 1);
  for (long long i = 1; i <= n; ++i) {
    cin >> arr[i];
    if (arr[i] != 1 && arr[i] != -1) {
      bpos = i;
    }
  }
  // if (n == 1) {
  //   cout << 2 << endl;
  //   cout << 0 << ' ' << arr[1] << endl;
  //   return ;
  // }

  long long spval = arr[bpos];
  vector<long long> larr(bpos);
  vector<long long> rarr(n - bpos + 1);
  for (long long i = 1; i < bpos; ++i) {
    larr[i] = arr[i] + larr[i - 1];
  }
  for (long long i = bpos + 1; i <= n; ++i) {
    rarr[i - bpos] = arr[i] + rarr[i - bpos - 1];
  }
  set<long long> ans;
  auto [min1, max1] = maxGap(larr);
  auto [min2, max2] = maxGap(rarr);
  for (long long i = min1; i <= max1; ++i) {
    ans.insert(i);
  }
  for (long long i = min2; i <= max2; ++i) {
    ans.insert(i);
  }
  // prlong longf("ss %d %d %d %d\n", min1, max1, min2, max2);
  long long lmax = 0;
  long long lmin = 0;
  long long rmax = 0;
  long long rmin = 0;
  long long lsum = 0;
  for (long long i = bpos - 1; i >= 1; i--) {
    lsum += arr[i];
    lmax = max(lsum, lmax);
    lmin = min(lmin, lsum);
  }
  long long rsum = 0;
  for (long long i = bpos + 1; i <= n; ++i) {
    rsum += arr[i];
    rmax = max(rmax, rsum);
    rmin = min(rmin, rsum);
  }
  // prlong longf("lmin %d lmax  %d rmin %d rmax %d\n", lmin, lmax, rmin, rmax);
  long long lbound = arr[bpos] + lmin + rmin;
  long long rbound = arr[bpos] + lmax + rmax;
  // prlong longf(" lr bound :%d %d\n", lbound, rbound);
  for (long long i = lbound; i <= rbound; ++i) {
    ans.insert(i);
  }
  cout << ans.size() << endl;
  for (auto e : ans) {
    cout << e << ' ';
  }
  cout << endl;
}

int main() {
  long long t;
  cin >> t;
  while (t--)
    solve();
}
