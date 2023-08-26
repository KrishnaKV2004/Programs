#include <stdio.h>

int factorial(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * i;
  }
  return res;
}

int nCr(int n, int r) {
  return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
  int rows;
  printf("Enter number of rows: ");
  scanf("%d", &rows);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d ", nCr(i, j));
    }
    printf("\n");
  }
  return 0;
}