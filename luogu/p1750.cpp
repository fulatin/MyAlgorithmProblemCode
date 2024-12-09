#include <deque>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  vector<long long> arr(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  deque<long long> q;
  for (int i = 1; i <= c; ++i) {
    while (!q.empty() && q.back() > arr[i])
      q.pop_back();
    q.push_back(arr[i]);
  }
  int l = 1, r = c, outcnt = 0;
  stack<long long> s;
  while (outcnt < n) {
    if (q.empty() || !s.empty() && s.top() < q.front()) {
      cout << s.top() << ' ';
      s.pop();
      outcnt++;
      if (r == n)
        continue;

      while (!q.empty() && arr[r + 1] < q.back())
        q.pop_back();
      q.push_back(arr[++r]);
    } else {
      while (arr[l] > q.front()) {
        s.push(arr[l++]);
      }
      cout << arr[l++] << ' ';
      outcnt++;
      q.pop_front();
      if (r == n)
        continue;

      while (!q.empty() && arr[r + 1] < q.back())
        q.pop_back();
      q.push_back(arr[++r]);
    }
  }
  while (!s.empty())
    cout << s.top() << ' ', s.pop();
  return 0;
}
