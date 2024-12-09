#include <bits/stdc++.h>
#include <string>

using namespace std;

string resolve(string s) {
  string ls;
  for (int i = 0; i < s.size(); ++i) {
    ls += s[i];
    if (s[i] == '(') {
      int num = 0;
      int j;
      for (j = i + 1; isdigit(s[j]); ++j) {
        num = num * 10 + s[j] - '0';
      }
      // cout << "num is " << num << endl;
      string mid;
      int k = 0;
      while (num > 0) {
        if (num % 2)
          mid =
              (k == 1 ? "2+" : to_string(2) + "(" + to_string(k) + ")+") + mid;
        k++;
        num /= 2;
      }
      if (!mid.empty())
        mid.pop_back();
      else
        mid.append("0");
      // cout << "mid is " << mid << endl;
      string rs;
      for (int k = j; k < s.size(); ++k) {
        rs += s[k];
      }
      return ls + resolve(mid) + resolve(rs);
    }
  }
  return ls;
}

int main() {
  string s;

  cin >> s;
  s = "(" + s + ')';
  string res = resolve(s);
  for (int i = 1; i < res.size() - 1; ++i) {
    cout << res[i];
  }

  return 0;
}
