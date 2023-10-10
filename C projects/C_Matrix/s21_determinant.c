#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  if (A->columns > 0 && A->rows > 0) {
    if (A->rows == A->columns) {
      *result = s21_find_determinant(A->matrix, A->rows, A->columns);
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}
