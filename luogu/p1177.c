#include <stdio.h>
#include <stdlib.h>
const int MAXN = 100000 + 3;
int a[MAXN];
void quicksort(int l, int h) {
  int left = l;
  int right = h;
  int pivot = a[left];

  if (left >= right)
    return;

  while (left < right) {
    while (left < right && a[right] >= pivot)
      right--;
    a[left] = a[right];
    while (left < right && a[left] <= pivot)
      left++;
    a[right] = a[left];
  }
  a[left] = pivot;

  quicksort(l, left - 1);
  quicksort(left + 1, h);
}

int main() {
  int n;
  scanf("%d", &n);
  /* int *a = (int *)malloc(n * sizeof(int)); */
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  quicksort(0, n - 1);
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  /* free(a); */
  return 0;
}
