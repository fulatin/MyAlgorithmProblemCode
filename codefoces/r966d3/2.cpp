
#include <cctype>
#include <cstdio>
bool sts[2 * (int)10e5 + 2];
int rd() {
  int rt = 0;
  char in;
  while (isdigit(in = getchar())) {
    rt = rt * 10 + in - '0';
  }
  return rt;
}

void cs() {
  int n = rd();
  for (int i = 1; i <= n; ++i) {
    sts[i] = false;
  }
  int first = rd();
  sts[first + 1] = true;
  sts[first - 1] = true;
  int i = 0;
  bool pass = true;
  for (i = 2; i <= n; ++i) {
    int next = rd();
    if (!sts[next]) {
      pass = false;
    } else {
      sts[next - 1] = true;
      sts[next + 1] = true;
    }
  }

  if (pass)
    printf("YES\n");
  else
    printf("NO\n");
  return;
}
int main() {
  int cases = rd();
  while (cases--) {
    cs();
  }
  return 0;
}
