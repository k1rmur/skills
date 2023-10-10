#include "s21_matrix.h"

void s21_find_minor(matrix_t *tmp, matrix_t A, int c, int r) {
  int i2 = 0;
  for (int i = 0; i < A.rows; i++) {
    if (i == r) {
      continue;
    } else {
      int j2 = 0;
      for (int j = 0; j < A.columns; j++) {
        if (j != c) {
          tmp->matrix[i2][j2] = A.matrix[i][j];
          j2++;
        }
      }
      i2++;
    }
  }
}

double s21_find_determinant(double **matrix, int n, int m) {
  double d = 0;
  if (n == 1) {
    d = matrix[0][0];
  } else if (n == 2) {
    d = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    for (int k = 0; k < n; k++) {
      double **ma = malloc(n * n * sizeof(double) + m * sizeof(double *));
      double *ptr = (double *)(ma + m);
      for (int i = 0; i < m; i++) {
        ma[i] = ptr + n * i;
      }
      for (int i = 1; i < n; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
          if (j == k) continue;
          ma[i - 1][t] = matrix[i][j];
          t++;
        }
      }
      d += pow(-1, k + 2) * matrix[0][k] *
           s21_find_determinant(ma, n - 1, m - 1);
      free(ma);
    }
  }
  return d;
}