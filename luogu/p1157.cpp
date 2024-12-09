#include <bits/stdc++.h>

using namespace std;

int n, r;

void solve(vector<int> v, int pos) {
  if (pos > n + 1) {
    return;
  }
  if (v.size() == r) {
    for (auto e : v) {
      cout << setw(3) << e;
    }
    cout << endl;
    return;
  }
  v.push_back(pos);
  solve(v, pos + 1);
  v.pop_back();
  solve(v, pos + 1);
}

int main() {

  cin >> n >> r;
  vector<int> v;
  solve(v, 1);
  return 0;
}
