#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 1e4;
vector<int> v(SIZE);

int main() {

  srand(time(0));
  for (int i = 0; i < SIZE; ++i) {
    v[i] = rand() % SIZE;
  }
  int len = v.size();
  for (int i = 0; i < len - 1; ++i) {
    for (int j = 0; j < len - i - 1; ++j) {
      if (v[j] > v[j + 1]) {
        int tmp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = tmp;
      }
    }
  }
  for (auto e : v)
    cout << e << ' ';
  cout << endl;
  return 0;
}
