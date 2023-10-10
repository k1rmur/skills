#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (A->columns > 0 && A->rows > 0) {
    if (A->columns == 1 && A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = A->matrix[0][0];
    } else {
      if (A->columns == A->rows) {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
          }
        }
        matrix_t tmp = {0};
        for (int r = 0; r < A->rows; r++) {
          for (int c = 0; c < A->columns; c++) {
            s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
            s21_find_minor(&tmp, *A, c, r);
            result->matrix[r][c] =
                s21_find_determinant(tmp.matrix, A->rows - 1, A->columns - 1);
            s21_remove_matrix(&tmp);
          }
        }
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] *= pow(-1, i + j);
          }
        }
      } else {
        res = 2;
      }
    }
  } else {
    res = 1;
  }
  return res;
}