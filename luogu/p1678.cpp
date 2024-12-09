#include <bits/stdc++.h>

using namespace std;

int m, n;
int main() {
  cin >> m >> n;
  vector<int> schools(m);
  vector<int> score(n + 1);
  for (int i = 0; i < m; ++i)
    cin >> schools[i];

  for (int i = 0; i < n; ++i) {
    // cout << i << endl;
    cin >> score[i];
    // cout << score[i] << endl;
  }
  sort(schools.begin(), schools.end());
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int currs = score[i];
    int l = 0;
    int r = m - 1;
    while (r - l > 1) {
      // cout << l << ' ' << r << endl;
      int mid = (l + r) >> 1;
      if (schools[mid] == currs) {
        l = mid;
        r = mid;
        break;
      } else if (schools[mid] > currs)
        r = mid;
      else
        l = mid;
    }
    ans += min(abs(currs - schools[l]), abs(schools[r] - currs));
  }

  cout << ans;
}
