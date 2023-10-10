#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  long double a = 0;
  long double b = 0;
  if (A->columns == B->columns && B->rows == A->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] < 0) {
          A->matrix[i][j] *= -1;
          B->matrix[i][j] *= -1;
        }
        a = A->matrix[i][j] * pow(10, 7);
        b = B->matrix[i][j] * pow(10, 7);
        if (floor(a) != floor(b)) {
          res = FAILURE;
        }
      }
    }
  } else {
    res = FAILURE;
  }
  return res;
}
