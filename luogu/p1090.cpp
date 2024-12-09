#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

int n;

priority_queue<int, vector<int>, greater<int>> pq;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    pq.push(curr);
  }
  int tili = 0;
  while (pq.size() > 1) {
    int a, b;
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    int c = a + b;
    tili += a + b;
    pq.push(c);
  }
  cout << tili;
}
