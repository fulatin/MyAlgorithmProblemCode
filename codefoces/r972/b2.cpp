
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000000000;

int t, n, q, m;
vector<int> teacher;

void solve() {
  teacher.clear();
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    int curr;
    cin >> curr;
    teacher.push_back(curr);
  }
  sort(teacher.begin(), teacher.end());
  while (q--) {
    int pos;
    cin >> pos;
    int left = -1;
    int right = m;
    while (right - left > 1) {
      int mid = (left + right) >> 1;
      if (teacher[mid] > pos) {
        right = mid;
      } else {
        left = mid;
      }
    }
    if (left == -1) {
      cout << teacher[right] - 1;
      cout << endl;
    } else if (right == m) {
      cout << n - teacher[left];
      cout << endl;
    } else {

      cout << ((teacher[right] - teacher[left]) >> 1) << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
