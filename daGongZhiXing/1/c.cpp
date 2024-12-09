#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

int renxing[MAXN];
bool ruohuo[MAXN];
bool xushu[MAXN];

vector<int> diren(7);
int nowrenxing[7];
int pos;
int n, q;

int buchongacheck() {
  int diecnt = 0;
  for (int i = 1; i <= 5; ++i) {
    if (nowrenxing[i] <= 0) {
      // cout << "在" << i << "处补充了" << pos << endl;
      diren[i] = pos++;
      pos %= n;
      nowrenxing[i] = renxing[diren[i]];
      diecnt++;
    }
  }
  return diecnt;
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> renxing[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> ruohuo[i];
    cin >> xushu[i];
  }
  buchongacheck();
  while (q--) {

    int tp, atpos;
    cin >> tp >> atpos;
    // atpos--;
    if (tp == 0) {
      // cout << "ok" << xushu[diren[atpos]] << endl;
      if (xushu[diren[atpos]]) {
        nowrenxing[atpos] -= 2;
      }
    } else {
      nowrenxing[atpos - 1] -= ruohuo[diren[atpos - 1]] ? 2 : 1;
      nowrenxing[atpos + 1] -= ruohuo[diren[atpos + 1]] ? 2 : 1;
      if (ruohuo[diren[atpos]]) {
        nowrenxing[atpos] -= 6;
      } else {
        nowrenxing[atpos] -= 3;
      }
    }
    // for (int i = 1; i <= 5; ++i) {
    //   cout << nowrenxing[i] << ' ';
    // }
    // cout << endl;
    cout << buchongacheck() << endl;
  }
  return 0;
}
