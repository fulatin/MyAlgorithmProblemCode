
#include <stdio.h>

int ans[10];

int main() {

  int arr1[5] = {1, 3, 4, 5, 7};

  int arr2[5] = {2, 4, 6, 7, 8};

  int i1 = 0, i2 = 0;

  int anspos = 0;

  while (i1 < 5 || i2 < 5) {

    if (i1 > 5) {

      for (; i2 < 5; i2++, anspos++) {

        ans[anspos] = arr2[i2];
      }

    } else if (i2 > 5) {

      for (; i1 < 5; i1++, anspos++) {

        ans[anspos] = arr1[i1];
      }

    } else {

      if (arr1[i1] < arr2[i2]) {

        ans[anspos++] = arr1[i1++];

      } else {

        ans[anspos++] = arr2[i2++];
      }
    }
  }

  for (int i = 0; i < anspos; ++i) {

    printf("%d ", ans[i]);
  }
}
