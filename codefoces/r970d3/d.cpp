#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t;
vector<int> arr, ans;

vector<bool> isblack;
vector<bool> vis;
void solve() {
  int n;
  cin >> n;
  arr.clear();
  isblack.clear();
  vis.clear();
  ans.clear();
  arr.resize(n + 1);
  vis.resize(n + 1, false);
  isblack.resize(n + 1);
  ans.resize(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; ++i) {
    char curr;
    cin >> curr;
    curr == '1' ? isblack[i] = false : isblack[i] = true;
  }
  for (int i = 1; i <= n; ++i) {
    int curr = i;
    queue<int> contain;
    int cnt = 0;

    while (!vis[curr]) {
      contain.push(curr);
      isblack[curr] ? cnt++ : NULL;
      vis[curr] = true;

      curr = arr[curr];
    }
    while (!contain.empty()) {
      ans[contain.front()] = cnt;
      contain.pop();
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
