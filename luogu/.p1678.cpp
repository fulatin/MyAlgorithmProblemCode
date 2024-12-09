#include <bits/stdc++.h>
#include <climits>

using namespace std;

int n, m;
bool school[1000000 + 3];

int main() {
  cin >> m >> n;
  int maxs = -1;
  int mins = INT_MAX;
  for (int i = 1; i <= m; ++i) {
    int idx;
    cin >> idx;
    mins = min(mins, idx);
    maxs = max(maxs, idx);
    school[idx] = true;
  }
  int cnt = 0;
  while (n--) {
    int score;
    cin >> score;
    int j;
    for (j = score; j <= maxs; ++j) {
      if (school[j])
        break;
    }
    int k;
    for (k = score; k >= mins; --k) {
      if (school[k])
        break;
    }

    cnt += min(j - score, score - k);
  }
  cout << cnt;
}
