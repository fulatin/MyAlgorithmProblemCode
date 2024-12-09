#include <bits/stdc++.h>

using namespace std;

int s1, s2, s3, s4;
#define f(i, a, b) for (int i = a; i <= b; ++i)
vector<int> tasks[4];

int tmpans;
void search(int pos, int l, int r, int t) {
  if (pos >= tasks[t].size()) {
    int m = max(l, r);
    if (m < tmpans)
      tmpans = m;
    return;
  }

  search(pos + 1, l + tasks[t][pos], r, t);
  search(pos + 1, l, r + tasks[t][pos], t);
}

int main() {
  cin >> s1 >> s2 >> s3 >> s4;

  f(i, 1, s1) {
    int curr;
    cin >> curr;
    tasks[0].push_back(curr);
  }
  f(i, 1, s2) {
    int curr;
    cin >> curr;
    tasks[1].push_back(curr);
  }
  f(i, 1, s3) {
    int curr;
    cin >> curr;
    tasks[2].push_back(curr);
  }
  f(i, 1, s4) {
    int curr;
    cin >> curr;
    tasks[3].push_back(curr);
  }
  int total = 0;
  for (int i = 0; i < 4; ++i) {
    tmpans = 0x7fffffff;
    search(0, 0, 0, i);
    total += tmpans;
  }
  cout << total;
}
