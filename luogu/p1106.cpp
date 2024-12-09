#include <bits/stdc++.h>
#include <climits>

using namespace std;

char buffer[257];
int k;
bool chosen[257];
int main() {
  ios::sync_with_stdio(false);
  cin >> buffer;
  cin >> k;
  int n = strlen(buffer);
  int cnt = n - k;
  bool first = true;
  while (cnt--) {
    int m;
    if (first) {
      m = INT_MAX;
    } else {
      m = buffer[n - 1 - cnt] - '0';
    }
    int pos = n - 1 - cnt;
    for (int i = n - 1 - cnt; i >= 0; i--) {
      if (chosen[i])
        break;
      if (first && buffer[i] - '0' == 0)
        continue;
      if (buffer[i] - '0' <= m) {
        pos = i;
        m = buffer[i] - '0';
      }
    }

    chosen[pos] = true;
    cout << m;
    first = false;
  }
}
