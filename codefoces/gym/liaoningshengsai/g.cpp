#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 3;
int t, n, k;
int arr[MAXN];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];

  unordered_map<int, int> nxt;
  unordered_map<int, int> prev;
  vector<int> L(n + 1), R(n + 1);
  stack<int> tmp;
  for (int i = 1; i <= n; ++i) {
    while (!tmp.empty() && arr[tmp.top()] <= arr[i])
      tmp.pop();
    if (!tmp.empty())
      L[i] = tmp.top();
    else
      L[i] = 0;
    tmp.push(i);
  }
  while (!tmp.empty())
    tmp.pop();
  for (int i = n; i >= 1; --i) {
    while (!tmp.empty() && arr[tmp.top()] <= arr[i])
      tmp.pop();
    if (!tmp.empty())
      R[i] = tmp.top();
    else
      R[i] = n + 1;
    tmp.push(i);
  }
  unordered_map<int, queue<int>> hlpnxt;
  unordered_map<int, queue<int>> hlpprev;
  for (int i = 1; i <= n; ++i) {

    hlpnxt[arr[i]].push(i);
    if (hlpnxt[arr[i]].size() == k) {
      nxt[hlpnxt[arr[i]].front()] = i;
      hlpnxt[arr[i]].pop();
    }
    if (!hlpprev[arr[i]].empty()) {
      prev[i] = hlpprev[arr[i]].front();
      hlpprev[arr[i]].pop();
      hlpprev[arr[i]].push(i);
    } else {
      hlpprev[arr[i]].push(i);
    }
  }
  long long ans = 0;

  for (int i = 1; i <= n; ++i) {
    // cout << R[i] << ' ' << nxt[i] << endl;
    if (nxt[i] == 0 || R[i] < nxt[i])
      continue;
    int ll = max(L[i], prev[i]);
    ans += (i - ll) * (R[i] - nxt[i]);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--)
    solve();
}
