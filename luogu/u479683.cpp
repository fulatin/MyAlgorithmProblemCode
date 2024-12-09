#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

using namespace std;

int t;

char obuff[1 << 25];
char *buffptr = obuff;

void write(long long x) {
  static int sta[35];

  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top)
    *(buffptr++) = sta[--top] + 48;
  *(buffptr++) = '\n';
}
template <typename T> T read() {
  T sum = 0, fl = 1;
  int ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-')
      fl = -1;
  for (; isdigit(ch); ch = getchar())
    sum = sum * 10 + ch - '0';
  return sum * fl;
}

void wout() { fwrite(obuff, 1, 1 << 25, stdout); }

void solve() {
  long long n = read<long long>();
  // printf("%.0Lf\n",
  // ceill(((long double)0 + sqrtl(1 + 4 * (long double)n)) / 2.0));
  // ;
  long long res =
      ceill((((long double)-1.0 + sqrtl(1.0 + 4 * (long double)n))) / 2.0);
  write(res);
}

int main() {
  cout.setf(ios::fixed, ios::floatfield);
  cin >> t;
  while (t--) {
    solve();
  }
  wout();
  fflush(stdout);
}
