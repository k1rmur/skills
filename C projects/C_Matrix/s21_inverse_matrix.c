#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 0;
  double det = 0;
  if (A->rows > 0 && A->columns > 0) {
    if (A->rows > 1 && A->columns > 1) {
      res = s21_determinant(A, &det);
      if (res == 0) {
        if (fabs(det) > 1e-6 && det != 0) {
          matrix_t tmp = {0};
          matrix_t tmp2 = {0};
          res = s21_calc_complements(A, &tmp);
          if (res == 0) {
            res = s21_transpose(&tmp, &tmp2);
          }
          if (res == 0) {
            res = s21_mult_number(&tmp2, 1.0 / det, result);
            s21_remove_matrix(&tmp);
            s21_remove_matrix(&tmp2);
          }
        } else {
          res = 2;
        }
      }
    } else {
      if (A->rows == 1 && A->columns == 1 && A->matrix[0][0] != 0) {
        s21_create_matrix(A->rows, A->columns, result);
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        res = 2;
      }
    }
  } else {
    res = 1;
  }
  return res;
}