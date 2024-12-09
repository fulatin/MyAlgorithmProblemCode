#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;
unordered_map<string, int> namemap;
int n, a, sizes;

void pop(priority_queue<int, vector<int>, greater<>> &q1,
         priority_queue<int, vector<int>, greater<>> &q2) {
  while (!q1.empty() && !q2.empty() && q1.top() == q2.top()) {
    q1.pop();
    q2.pop();
    sizes--;
  }
}
void pop(priority_queue<int, vector<int>> &q1,
         priority_queue<int, vector<int>> &q2) {
  while (!q1.empty() && !q2.empty() && q1.top() == q2.top()) {
    q1.pop();
    q2.pop();
  }
}
int main() {
  cin >> n >> a;
  priority_queue<int, vector<int>, greater<>> a1, a2;
  priority_queue<int, vector<int>> b1, b2;
  int cnt = 0;
  sizes = a;
  for (int i = 0; i < n; ++i) {
    string tp;
    cin >> tp;
    string name;
    cin >> name;

    if (tp[0] == '1') {
      cnt++;
      int shili;
      cin >> shili;
      namemap[name] = shili;

      if (a1.size() < sizes) {
        a1.push(shili);
      } else if (shili < a1.top()) {
        b1.push(shili);
      } else {
        b1.push(a1.top());
        a1.pop();
        a1.push(shili);
      }
    } else {
      cnt--;
      int val = namemap[name];
      if (val >= a1.top()) {
        a2.push(val);
        sizes++;
        if (!b1.empty()) {
          a1.push(b1.top());
          b1.pop();
        }
      } else {
        b2.push(val);
      }
    }
    pop(a1, a2);
    pop(b1, b2);
    if (cnt < a) {
      cout << -1 << endl;
    } else {
      cout << a1.top() << endl;
    }
  }
}
