#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long LL;

LL L, N, K;
priority_queue<int, vector<int>> q;

bool check(LL x) {
  priority_queue<int> cq = priority_queue<int>(q);
  LL used = 0;
  while (true) {
    if (cq.top() <= x)
      return 1;
    if (used == K)
      return 0;
    LL t = cq.top();
    cq.pop();
    cq.push(x);
    cq.push(t - x);
    used++;
  }
}

int main() {
  cin >> L >> N >> K;

  LL last;
  cin >> last;
  for (int i = 1; i <= N - 1; ++i) {
    LL curr;
    cin >> curr;
    q.push(curr - last);
    last = curr;
  }
  LL l = 1, r = L;
  while (l <= r) {
    LL mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << r + 1;
  return 0;
}
