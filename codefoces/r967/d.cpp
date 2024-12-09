#include <cstring>
#include <iostream>
#include <set>
using namespace std;

#define MAXN 3 * (int)10e5 + 4

int n, cases, arr[MAXN], poss[MAXN], pose[MAXN];

int resarr[MAXN];
void solve() {
  set<int> rest;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    arr[i] = curr;
    if (!poss[curr]) {
      poss[curr] = i;
      pose[curr] = i;
      rest.insert(curr);
    }
    pose[curr] = i;
  } // record the start pos and end pos of every distinct num

  int idx = 0;
  int resc = 0;
  while (!rest.empty()) {
    int curres = (resc + 1) % 2 == 0 ? MAXN : -1;
    for (int i = idx + 1; i <= n; ++i) {
      if (rest.find(arr[i]) == rest.end())
        continue;
      curres = (resc + 1) % 2 == 0 ? min(curres, arr[i]) : max(curres, arr[i]);
      if (pose[arr[i]] == i)
        break;
    }
    resarr[++resc] = curres;
    rest.erase(curres);
    idx = poss[curres];
  }
  cout << resc << endl;
  cout << resarr[1];
  for (int i = 2; i <= resc; ++i) {
    cout << ' ' << resarr[i];
  }
  cout << endl;
  for (int i = 1; i <= n; ++i) {
    poss[i] = 0;
  }
}

int main() {
  cin >> cases;
  while (cases--)
    solve();
}
