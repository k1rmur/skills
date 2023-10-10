#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

// Создание и удаление матрицы
START_TEST(s21_alloc_and_destroy_test_1) {
  matrix_t a = {0};
  int row = -2;
  int column = 1;
  int result = s21_create_matrix(row, column, &a);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_alloc_and_destroy_test_2) {
  matrix_t a = {0};
  int row = 1;
  int column = 1;
  int result = s21_create_matrix(row, column, &a);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_alloc_and_destroy_test_3) {
  matrix_t a = {0};
  int row = 1;
  int column = 5;
  int result = s21_create_matrix(row, column, &a);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_alloc_and_destroy_test_4) {
  matrix_t a = {0};
  int row = 52;
  int column = 1;
  int result = s21_create_matrix(row, column, &a);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_alloc_and_destroy_test_5) {
  matrix_t a = {0};
  int row = 0;
  int column = 1;
  int result = s21_create_matrix(row, column, &a);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_alloc_and_destroy_test_6) {
  matrix_t a = {0};
  int row = 35;
  int column = 0;
  int result = s21_create_matrix(row, column, &a);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_alloc_and_destroy_test_7) {
  matrix_t a = {0};
  int row = 13;
  int column = -1;
  int result = s21_create_matrix(row, column, &a);
  ck_assert_int_eq(1, result);
}
END_TEST

// Сравнение
START_TEST(s21_eq_matrix_test_1) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(6, 2, &a);
  s21_create_matrix(6, 2, &b);
  int result = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  a.matrix[0][0] = 1;
  b.matrix[0][0] = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = -1234.892345567;
      b.matrix[i][j] = -1234.892345581;
    }
  }
  int result = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(6, 1, &a);
  s21_create_matrix(1, 6, &b);
  a.matrix[0][0] = 1;
  b.matrix[0][0] = 1;
  int result = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = -135552135556.12345678;
  a.matrix[1][0] = -23523414445556;
  a.matrix[1][1] = 1;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = -135552135556.12345671;
  b.matrix[1][0] = -23523414445556;
  b.matrix[1][1] = 1;

  int result = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  a.matrix[0][0] = 0;
  a.matrix[0][1] = -1123.12345679;
  a.matrix[1][0] = -235;
  a.matrix[1][1] = -1;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = -1123.12345671;
  b.matrix[1][0] = -235;
  b.matrix[1][1] = 1;

  int result = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

// Транспонирование матриц
START_TEST(s21_transpose_test_1) {
  matrix_t a = {0};
  matrix_t result = {0};
  int res = s21_transpose(&a, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t a = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 5, &a);
  s21_create_matrix(5, 2, &check);
  int tran_result = s21_transpose(&a, &result);
  int res = s21_eq_matrix(&a, &result);
  ck_assert_int_eq(tran_result, 0);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t a = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  s21_create_matrix(11, 1, &a);
  s21_create_matrix(1, 11, &check);
  int tran_result = s21_transpose(&a, &result);
  int res = s21_eq_matrix(&a, &result);
  ck_assert_int_eq(tran_result, 0);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  matrix_t a = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 4, &a);
  s21_create_matrix(5, 4, &check);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i * j;
      check.matrix[j][i] = i * j;
    }
  }
  int tran_result = s21_transpose(&a, &result);
  int res = s21_eq_matrix(&a, &result);
  ck_assert_int_eq(tran_result, 0);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_transpose_test_5) {
  matrix_t a = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &check);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + 21;
      check.matrix[j][i] = 2 * i;
    }
  }
  int tran_result = s21_transpose(&a, &result);
  int res = s21_eq_matrix(&a, &result);
  ck_assert_int_eq(tran_result, 0);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_transpose_test_6) {
  matrix_t a = {0};
  matrix_t check = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 12, &a);
  s21_create_matrix(12, 5, &check);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j * 4;
      check.matrix[j][i] = i + j * 4;
    }
  }
  int tran_result = s21_transpose(&a, &result);
  int res = s21_eq_matrix(&a, &result);
  ck_assert_int_eq(tran_result, 0);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

// Сложение матриц
START_TEST(s21_sum_matrix_test_1) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  s21_create_matrix(99, 100, &a);
  s21_create_matrix(100, 99, &b);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j * 4;
      b.matrix[j][i] = i + j * 4;
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 6, &a);
  s21_create_matrix(5, 5, &b);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i * 21;
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 5, &a);
  s21_create_matrix(5, 5, &b);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i * j * (i + 2);
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 5, &a);
  s21_create_matrix(2, 5, &b);
  s21_create_matrix(2, 5, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i * i * -123.123;
      b.matrix[i][j] = i - j - 21;
      c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(30, 30, &a);
  s21_create_matrix(30, 30, &b);
  s21_create_matrix(30, 30, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = j + j * (i - j + 12.2222);
      b.matrix[i][j] = -0.0001 * 43 * i;
      c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_6) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 10, &a);
  s21_create_matrix(5, 10, &b);
  s21_create_matrix(5, 10, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i * i + i * j + 44.0004;
      b.matrix[i][j] = j;
      c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_7) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 100, &a);
  s21_create_matrix(1, 100, &b);
  s21_create_matrix(1, 100, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i * 74 * j;
      b.matrix[i][j] = 22 * i * j;
      c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_8) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 4, &a);
  s21_create_matrix(4, 4, &b);
  s21_create_matrix(4, 4, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = 0;
      b.matrix[i][j] = -1;
      c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_9) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 4, &a);
  s21_create_matrix(4, 4, &b);
  s21_create_matrix(4, 4, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = 0.000000000023;
      b.matrix[i][j] = -1.00001 * i;
      c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
    }
  }
  int res = s21_sum_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

// Вычитание
START_TEST(s21_sub_matrix_test_1) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(10, 10, &a);
  s21_create_matrix(10, 10, &b);
  s21_create_matrix(10, 10, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i * j * (j - 10.0000001);
      b.matrix[i][j] = -j * 34;
      c.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
    }
  }
  int res = s21_sub_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 31, &a);
  s21_create_matrix(5, 31, &b);
  s21_create_matrix(5, 31, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i * j * -0.000099;
      b.matrix[i][j] = i + j + 5.9999;
      c.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
    }
  }
  int res = s21_sub_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_3) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 100, &a);
  s21_create_matrix(1, 100, &b);
  s21_create_matrix(1, 100, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = -0.0021 * i * 0.01;
      b.matrix[i][j] = j - 2;
      c.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
    }
  }
  int res = s21_sub_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_4) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 2, &a);
  s21_create_matrix(1, 2, &b);
  s21_create_matrix(1, 2, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = (i + j) * 12.0441;
      b.matrix[i][j] = i + j * 155.2301;
      c.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
    }
  }
  int res = s21_sub_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_5) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(8, 5, &a);
  s21_create_matrix(8, 5, &b);
  s21_create_matrix(8, 5, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i + j + 5;
      b.matrix[i][j] = i + j + 1;
      c.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
    }
  }
  int res = s21_sub_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_6) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  s21_create_matrix(51, 2, &a);
  s21_create_matrix(51, 1, &b);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = 2352135 * 133.12;
    }
  }
  int res = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_sub_matrix_test_7) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 2, &a);
  s21_create_matrix(2, 5, &b);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = 2352135 * 133.12;
    }
  }
  int res = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_sub_matrix_test_8) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  int res = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_sub_matrix_test_9) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 16, &a);
  s21_create_matrix(3, 16, &b);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = 2352135 * 133.12;
    }
  }
  int res = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_sub_matrix_test_10) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  a.rows = -1;
  a.columns = 100;
  int res = s21_sub_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

// Умножение матрицы на число
START_TEST(s21_mult_number_test_1) {
  matrix_t a = {0};
  matrix_t result = {0};
  int res = s21_mult_number(&a, 12.43, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  double d = -1235.234;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = d - 100 * i;
      c.matrix[i][j] = a.matrix[i][j] * d;
    }
  }
  int res = s21_mult_number(&a, d, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  double d = 0.123234;
  s21_create_matrix(5, 11, &a);
  s21_create_matrix(5, 11, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = d - j + i * d;
      c.matrix[i][j] = a.matrix[i][j] * d;
    }
  }
  int res = s21_mult_number(&a, d, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  double d = -5.033;
  s21_create_matrix(12, 12, &a);
  s21_create_matrix(12, 12, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = -(i + j) * 51.5002 * (int)d;
      c.matrix[i][j] = a.matrix[i][j] * d;
    }
  }
  int res = s21_mult_number(&a, d, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_5) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  double d = 0;
  s21_create_matrix(9, 4, &a);
  s21_create_matrix(9, 4, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = (i + j) * -11.3111111;
      c.matrix[i][j] = a.matrix[i][j] * d;
    }
  }
  int res = s21_mult_number(&a, d, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_6) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  double d = 123;
  s21_create_matrix(3, 1, &a);
  s21_create_matrix(3, 1, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = 0;
      c.matrix[i][j] = a.matrix[i][j] * d;
    }
  }
  int res = s21_mult_number(&a, d, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_7) {
  matrix_t a = {0};
  matrix_t result = {0};
  double d = 100.123;
  int res = s21_mult_number(&a, d, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_number_test_8) {
  matrix_t a = {0};
  matrix_t result = {0};
  double d = 0;
  int res = s21_mult_number(&a, d, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

// Умножение матрицы на матрицу
START_TEST(s21_mult_matrix_test_1) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  int res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 1, &a);
  s21_create_matrix(5, 2, &b);
  int res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 5, &a);
  s21_create_matrix(1, 5, &b);
  int res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  s21_create_matrix(1, 1, &c);
  a.matrix[0][0] = 123.777;
  b.matrix[0][0] = -10;
  c.matrix[0][0] = -1237.77;
  int res = s21_mult_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 4, &a);
  s21_create_matrix(4, 4, &b);
  s21_create_matrix(4, 4, &c);
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i;
      b.matrix[i][j] = i + j;
    }
  }
  c.matrix[0][0] = 0;
  c.matrix[0][1] = 0;
  c.matrix[0][2] = 0;
  c.matrix[0][3] = 0;
  c.matrix[1][0] = 6;
  c.matrix[1][1] = 10;
  c.matrix[1][2] = 14;
  c.matrix[1][3] = 18;
  c.matrix[2][0] = 12;
  c.matrix[2][1] = 20;
  c.matrix[2][2] = 28;
  c.matrix[2][3] = 36;
  c.matrix[3][0] = 18;
  c.matrix[3][1] = 30;
  c.matrix[3][2] = 42;
  c.matrix[3][3] = 54;
  int res = s21_mult_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_6) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 4, &a);
  s21_create_matrix(4, 4, &b);
  s21_create_matrix(4, 4, &c);
  double num = 21.1;
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = num * j + i - 22;
      b.matrix[i][j] = num * i + 1;
    }
  }
  c.matrix[0][0] = 3486.34;
  c.matrix[0][1] = 3486.34;
  c.matrix[0][2] = 3486.34;
  c.matrix[0][3] = 3486.34;
  c.matrix[1][0] = 3616.94;
  c.matrix[1][1] = 3616.94;
  c.matrix[1][2] = 3616.94;
  c.matrix[1][3] = 3616.94;
  c.matrix[2][0] = 3747.54;
  c.matrix[2][1] = 3747.54;
  c.matrix[2][2] = 3747.54;
  c.matrix[2][3] = 3747.54;
  c.matrix[3][0] = 3878.14;
  c.matrix[3][1] = 3878.14;
  c.matrix[3][2] = 3878.14;
  c.matrix[3][3] = 3878.14;
  int res = s21_mult_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_7) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 2, &a);
  s21_create_matrix(2, 4, &b);
  s21_create_matrix(4, 4, &c);
  double num = -5;
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = num;
      num++;
    }
  }
  num = 1;
  for (int i = 0; i < b.rows; i++) {
    for (int j = 0; j < b.columns; j++) {
      b.matrix[i][j] = num;
      num++;
    }
  }
  c.matrix[0][0] = -25.0;
  c.matrix[0][1] = -34.0;
  c.matrix[0][2] = -43.0;
  c.matrix[0][3] = -52.0;
  c.matrix[1][0] = -13.0;
  c.matrix[1][1] = -18.0;
  c.matrix[1][2] = -23.0;
  c.matrix[1][3] = -28.0;
  c.matrix[2][0] = -1.0;
  c.matrix[2][1] = -2.0;
  c.matrix[2][2] = -3.0;
  c.matrix[2][3] = -4.0;
  c.matrix[3][0] = 11.0;
  c.matrix[3][1] = 14.0;
  c.matrix[3][2] = 17.0;
  c.matrix[3][3] = 20.0;
  int res = s21_mult_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_8) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 2, &a);
  s21_create_matrix(2, 1, &b);
  s21_create_matrix(3, 1, &c);
  double num = 11;
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = i - j * num - (j + i);
    }
  }
  for (int i = 0; i < b.rows; i++) {
    for (int j = 0; j < b.columns; j++) {
      b.matrix[i][j] = num * 33 + i;
      num--;
    }
  }
  c.matrix[0][0] = -3972;
  c.matrix[1][0] = -3972;
  c.matrix[2][0] = -3972;
  int res = s21_mult_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_9) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 3, &b);
  s21_create_matrix(2, 3, &c);
  double num = -9.31;
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = num * (num - j);
      num++;
    }
  }
  num = 10;
  for (int i = 0; i < b.rows; i++) {
    for (int j = 0; j < b.columns; j++) {
      b.matrix[i][j] = num + j + i;
      num++;
    }
  }
  c.matrix[0][0] = 3174.8962;
  c.matrix[0][1] = 3639.0928;
  c.matrix[0][2] = 4103.2894;
  c.matrix[1][0] = 1356.7762;
  c.matrix[1][1] = 1557.8128;
  c.matrix[1][2] = 1758.8494;
  int res = s21_mult_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_10) {
  matrix_t a = {0};
  matrix_t b = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 7, &a);
  s21_create_matrix(7, 5, &b);
  s21_create_matrix(1, 5, &c);
  double num = 2;
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = num;
      num += 2;
    }
  }
  num = 1;
  for (int i = 0; i < b.rows; i++) {
    for (int j = 0; j < b.columns; j++) {
      b.matrix[i][j] = num;
      num++;
    }
  }
  c.matrix[0][0] = 1176.0;
  c.matrix[0][1] = 1232.0;
  c.matrix[0][2] = 1288.0;
  c.matrix[0][3] = 1344.0;
  c.matrix[0][4] = 1400.0;
  int res = s21_mult_matrix(&a, &b, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

// Детерминант
START_TEST(s21_determinant_test_1) {
  matrix_t a = {0};
  double det = 0;
  int res = s21_determinant(&a, &det);
  ck_assert_int_eq(res, 1);
  ck_assert_double_eq(det, 0);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t a = {0};
  s21_create_matrix(3, 5, &a);
  double det = 0;
  int res = s21_determinant(&a, &det);
  ck_assert_int_eq(res, 2);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t a = {0};
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = -123.321;
  double det = 0;
  int res = s21_determinant(&a, &det);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(det, -123.321);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t a = {0};
  s21_create_matrix(7, 7, &a);
  double num = 1;
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = num;
      num++;
    }
  }
  double det = 0;
  int res = s21_determinant(&a, &det);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 1.0;
  a.matrix[0][1] = -77.0;
  a.matrix[0][2] = 1.0;
  a.matrix[1][0] = 2.0;
  a.matrix[1][1] = 77.0;
  a.matrix[1][2] = 8.0;
  a.matrix[2][0] = -1.5;
  a.matrix[2][1] = 11.0;
  a.matrix[2][2] = 32.0;
  double det = 0;
  int res = s21_determinant(&a, &det);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(det, 8365.5);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_determinant_test_6) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 1.1;
  a.matrix[0][1] = 1.0;
  a.matrix[0][2] = 2.0;
  a.matrix[1][0] = 3.0;
  a.matrix[1][1] = 1.0;
  a.matrix[1][2] = 2.0;
  a.matrix[2][0] = 3.0;
  a.matrix[2][1] = 100.0;
  a.matrix[2][2] = 122.0;
  double det = 0;
  int res = s21_determinant(&a, &det);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(det, 148.2);
  s21_remove_matrix(&a);
}
END_TEST

// Матрица алгебраических дополнений
START_TEST(s21_calc_complements_test_1) {
  matrix_t a = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 3, &a);
  int res = s21_calc_complements(&a, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t a = {0};
  matrix_t result = {0};
  int res = s21_calc_complements(&a, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = 112.0;
  a.matrix[0][1] = 243.0;
  a.matrix[0][2] = 3.0;
  a.matrix[0][3] = -8.0;
  a.matrix[1][0] = 47.0;
  a.matrix[1][1] = 51.0;
  a.matrix[1][2] = -66.0;
  a.matrix[1][3] = 99.0;
  a.matrix[2][0] = -74.0;
  a.matrix[2][1] = 85.0;
  a.matrix[2][2] = 97.0;
  a.matrix[2][3] = 63.0;
  a.matrix[3][0] = -13.0;
  a.matrix[3][1] = 79.0;
  a.matrix[3][2] = -99.0;
  a.matrix[3][3] = -121.0;
  s21_create_matrix(4, 4, &c);
  c.matrix[0][0] = -2879514.0;
  c.matrix[0][1] = -1236631.0;
  c.matrix[0][2] = -1685096.0;
  c.matrix[0][3] = 880697.0;
  c.matrix[1][0] = 1162090.0;
  c.matrix[1][1] = -714015.0;
  c.matrix[1][2] = 4046255.0;
  c.matrix[1][3] = -3901600.0;
  c.matrix[2][0] = 4362897.0;
  c.matrix[2][1] = -2049432.0;
  c.matrix[2][2] = -532912.0;
  c.matrix[2][3] = -1370781.0;
  c.matrix[3][0] = 3412773.0;
  c.matrix[3][1] = -1569493.0;
  c.matrix[3][2] = 3144517.0;
  c.matrix[3][3] = 1284666.0;
  int res = s21_calc_complements(&a, &result);
  int eq_res = s21_eq_matrix(&result, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = -1.0;
  a.matrix[0][1] = 2.0;
  a.matrix[0][2] = 7.0;
  a.matrix[0][3] = 9.0;
  a.matrix[1][0] = 1.0;
  a.matrix[1][1] = 0.0;
  a.matrix[1][2] = 0.0;
  a.matrix[1][3] = 0.0;
  a.matrix[2][0] = 47.0;
  a.matrix[2][1] = 13.0;
  a.matrix[2][2] = 17.0;
  a.matrix[2][3] = 21.0;
  a.matrix[3][0] = 22.0;
  a.matrix[3][1] = 7.0;
  a.matrix[3][2] = 1.0;
  a.matrix[3][3] = 3.0;
  s21_create_matrix(4, 4, &c);
  c.matrix[0][0] = 0.0;
  c.matrix[0][1] = -30.0;
  c.matrix[0][2] = -108.0;
  c.matrix[0][3] = 106.0;
  c.matrix[1][0] = 138.0;
  c.matrix[1][1] = -726.0;
  c.matrix[1][2] = -1137.0;
  c.matrix[1][3] = 1061.0;
  c.matrix[2][0] = 0.0;
  c.matrix[2][1] = 12.0;
  c.matrix[2][2] = 57.0;
  c.matrix[2][3] = -47.0;
  c.matrix[3][0] = 0.0;
  c.matrix[3][1] = 6.0;
  c.matrix[3][2] = -75.0;
  c.matrix[3][3] = 57.0;
  int res = s21_calc_complements(&a, &result);
  int eq_res = s21_eq_matrix(&result, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = -53123.1235;
  s21_create_matrix(1, 1, &c);
  c.matrix[0][0] = -53123.1235;
  int res = s21_calc_complements(&a, &result);
  int eq_res = s21_eq_matrix(&result, &c);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t a = {0};
  matrix_t result = {0};
  int res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t a = {0};
  s21_create_matrix(3, 1, &a);
  matrix_t result = {0};
  int res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t a = {0};
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 2;
  double d = 1.0 / 2.0;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(d, result.matrix[0][0]);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  double num = 1;
  for (int i = 0; i < a.rows; i++) {
    for (int j = 0; j < a.columns; j++) {
      a.matrix[i][j] = num;
      num++;
    }
  }
  matrix_t result = {0};
  int res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 3, &a);
  a.matrix[0][0] = 1.0;
  a.matrix[0][1] = 6348.0;
  a.matrix[0][2] = 1324.001;
  a.matrix[1][0] = 123.0;
  a.matrix[1][1] = 54.055;
  a.matrix[1][2] = 55.1;
  a.matrix[2][0] = 234.0;
  a.matrix[2][1] = 902.0;
  a.matrix[2][2] = 211.1;
  s21_create_matrix(3, 3, &c);
  c.matrix[0][0] = -5434257791566969.0 / 6688548866533803000.0;
  c.matrix[0][1] = -2586860422198265.0 / 836068608316725400.0;
  c.matrix[0][2] = 55641185189.0 / 9425357605528.0;
  c.matrix[1][0] = -7421005809023397.0 / 26754195466135210000.0;
  c.matrix[1][1] = -686581730753845.0 / 104508576039590670.0;
  c.matrix[1][2] = 4069925575.0 / 1178169700691.0;
  c.matrix[2][0] = 2457428250.0 / 1178169700691.0;
  c.matrix[2][1] = 37113250000.0 / 1178169700691.0;
  c.matrix[2][2] = -19518748625 / 1178169700691.0;
  int res = s21_inverse_matrix(&a, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 0.333;
  a.matrix[0][1] = -15.2;
  a.matrix[1][0] = 12.52521;
  a.matrix[1][1] = 52.22;
  s21_create_matrix(2, 2, &c);
  c.matrix[0][0] = 13055000 / 51943113.0;
  c.matrix[0][1] = 3800000 / 51943113.0;
  c.matrix[1][0] = -695845 / 11542914.0;
  c.matrix[1][1] = 9250 / 5771457.0;
  int res = s21_inverse_matrix(&a, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_7) {
  matrix_t a = {0};
  matrix_t c = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = -1.0;
  a.matrix[0][1] = 2.0;
  a.matrix[0][2] = 7.0;
  a.matrix[0][3] = 9.0;
  a.matrix[1][0] = 1.0;
  a.matrix[1][1] = 0.0;
  a.matrix[1][2] = 0.0;
  a.matrix[1][3] = 0.0;
  a.matrix[2][0] = 47.0;
  a.matrix[2][1] = 13.0;
  a.matrix[2][2] = 17.0;
  a.matrix[2][3] = 21.0;
  a.matrix[3][0] = 22.0;
  a.matrix[3][1] = 7.0;
  a.matrix[3][2] = 1.0;
  a.matrix[3][3] = 3.0;
  s21_create_matrix(4, 4, &c);
  c.matrix[0][0] = 0.0;
  c.matrix[0][1] = 1.0;
  c.matrix[0][2] = 0.0;
  c.matrix[0][3] = 0.0;
  c.matrix[1][0] = -5.0 / 23.0;
  c.matrix[1][1] = -121.0 / 23.0;
  c.matrix[1][2] = 2.0 / 23.0;
  c.matrix[1][3] = 1.0 / 23.0;
  c.matrix[2][0] = -18.0 / 23.0;
  c.matrix[2][1] = -379.0 / 46.0;
  c.matrix[2][2] = 19.0 / 46.0;
  c.matrix[2][3] = -25.0 / 46.0;
  c.matrix[3][0] = 53.0 / 69.0;
  c.matrix[3][1] = 1061.0 / 138.0;
  c.matrix[3][2] = -47.0 / 138.0;
  c.matrix[3][3] = 19.0 / 46.0;
  int res = s21_inverse_matrix(&a, &result);
  int eq_res = s21_eq_matrix(&c, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(eq_res, 1);
  s21_remove_matrix(&a);
  s21_remove_matrix(&c);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  TCase *tc = tcase_create("s21_inverse_matrix_core");
  Suite *s = suite_create("s21_inverse_matrix_tests");

  tcase_add_test(tc, s21_inverse_matrix_test_1);
  tcase_add_test(tc, s21_inverse_matrix_test_2);
  tcase_add_test(tc, s21_inverse_matrix_test_3);
  tcase_add_test(tc, s21_inverse_matrix_test_4);
  tcase_add_test(tc, s21_inverse_matrix_test_5);
  tcase_add_test(tc, s21_inverse_matrix_test_6);
  tcase_add_test(tc, s21_inverse_matrix_test_7);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_calc_complements_suite(void) {
  TCase *tc = tcase_create("s21_calc_complements_core");
  Suite *s = suite_create("s21_calc_complements_tests");

  tcase_add_test(tc, s21_calc_complements_test_1);
  tcase_add_test(tc, s21_calc_complements_test_2);
  tcase_add_test(tc, s21_calc_complements_test_3);
  tcase_add_test(tc, s21_calc_complements_test_4);
  tcase_add_test(tc, s21_calc_complements_test_5);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_determinant_suite(void) {
  TCase *tc = tcase_create("s21_determinant_core");
  Suite *s = suite_create("s21_determinant_tests");

  tcase_add_test(tc, s21_determinant_test_1);
  tcase_add_test(tc, s21_determinant_test_2);
  tcase_add_test(tc, s21_determinant_test_3);
  tcase_add_test(tc, s21_determinant_test_4);
  tcase_add_test(tc, s21_determinant_test_5);
  tcase_add_test(tc, s21_determinant_test_6);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_mult_matrix_suite(void) {
  TCase *tc = tcase_create("s21_mult_matrix_core");
  Suite *s = suite_create("s21_mult_matrix_tests");

  tcase_add_test(tc, s21_mult_matrix_test_1);
  tcase_add_test(tc, s21_mult_matrix_test_2);
  tcase_add_test(tc, s21_mult_matrix_test_3);
  tcase_add_test(tc, s21_mult_matrix_test_4);
  tcase_add_test(tc, s21_mult_matrix_test_5);
  tcase_add_test(tc, s21_mult_matrix_test_6);
  tcase_add_test(tc, s21_mult_matrix_test_7);
  tcase_add_test(tc, s21_mult_matrix_test_8);
  tcase_add_test(tc, s21_mult_matrix_test_9);
  tcase_add_test(tc, s21_mult_matrix_test_10);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_mult_number_suite(void) {
  TCase *tc = tcase_create("s21_mult_number_core");
  Suite *s = suite_create("s21_mult_number_tests");

  tcase_add_test(tc, s21_mult_number_test_1);
  tcase_add_test(tc, s21_mult_number_test_2);
  tcase_add_test(tc, s21_mult_number_test_3);
  tcase_add_test(tc, s21_mult_number_test_4);
  tcase_add_test(tc, s21_mult_number_test_5);
  tcase_add_test(tc, s21_mult_number_test_6);
  tcase_add_test(tc, s21_mult_number_test_7);
  tcase_add_test(tc, s21_mult_number_test_8);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_sub_matrix_suite(void) {
  TCase *tc = tcase_create("s21_sub_matrix_core");
  Suite *s = suite_create("s21_sub_matrix_tests");

  tcase_add_test(tc, s21_sub_matrix_test_1);
  tcase_add_test(tc, s21_sub_matrix_test_2);
  tcase_add_test(tc, s21_sub_matrix_test_3);
  tcase_add_test(tc, s21_sub_matrix_test_4);
  tcase_add_test(tc, s21_sub_matrix_test_5);
  tcase_add_test(tc, s21_sub_matrix_test_6);
  tcase_add_test(tc, s21_sub_matrix_test_7);
  tcase_add_test(tc, s21_sub_matrix_test_8);
  tcase_add_test(tc, s21_sub_matrix_test_9);
  tcase_add_test(tc, s21_sub_matrix_test_10);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_sum_matrix_suite(void) {
  TCase *tc = tcase_create("s21_sum_matrix_core");
  Suite *s = suite_create("s21_sum_matrix_tests");

  tcase_add_test(tc, s21_sum_matrix_test_1);
  tcase_add_test(tc, s21_sum_matrix_test_2);
  tcase_add_test(tc, s21_sum_matrix_test_3);
  tcase_add_test(tc, s21_sum_matrix_test_4);
  tcase_add_test(tc, s21_sum_matrix_test_5);
  tcase_add_test(tc, s21_sum_matrix_test_6);
  tcase_add_test(tc, s21_sum_matrix_test_7);
  tcase_add_test(tc, s21_sum_matrix_test_8);
  tcase_add_test(tc, s21_sum_matrix_test_9);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_transpose_suite(void) {
  TCase *tc = tcase_create("s21_transpose_core");
  Suite *s = suite_create("s21_transpose_tests");

  tcase_add_test(tc, s21_transpose_test_1);
  tcase_add_test(tc, s21_transpose_test_2);
  tcase_add_test(tc, s21_transpose_test_3);
  tcase_add_test(tc, s21_transpose_test_4);
  tcase_add_test(tc, s21_transpose_test_5);
  tcase_add_test(tc, s21_transpose_test_6);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_eq_matrix_suite(void) {
  TCase *tc = tcase_create("s21_eq_matrix_core");
  Suite *s = suite_create("s21_eq_matrix_tests");

  tcase_add_test(tc, s21_eq_matrix_test_1);
  tcase_add_test(tc, s21_eq_matrix_test_2);
  tcase_add_test(tc, s21_eq_matrix_test_3);
  tcase_add_test(tc, s21_eq_matrix_test_4);
  tcase_add_test(tc, s21_eq_matrix_test_5);

  suite_add_tcase(s, tc);

  return s;
}

Suite *s21_alloc_and_destroy_suite(void) {
  TCase *tc = tcase_create("s21_alloc_and_destroy_core");
  Suite *s = suite_create("s21_alloc_and_destroy_tests");

  tcase_add_test(tc, s21_alloc_and_destroy_test_1);
  tcase_add_test(tc, s21_alloc_and_destroy_test_2);
  tcase_add_test(tc, s21_alloc_and_destroy_test_3);
  tcase_add_test(tc, s21_alloc_and_destroy_test_4);
  tcase_add_test(tc, s21_alloc_and_destroy_test_5);
  tcase_add_test(tc, s21_alloc_and_destroy_test_6);
  tcase_add_test(tc, s21_alloc_and_destroy_test_7);

  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int failed = 0;
  SRunner *sr;

  sr = srunner_create(s21_alloc_and_destroy_suite());
  srunner_add_suite(sr, s21_eq_matrix_suite());
  srunner_add_suite(sr, s21_transpose_suite());
  srunner_add_suite(sr, s21_sum_matrix_suite());
  srunner_add_suite(sr, s21_sub_matrix_suite());
  srunner_add_suite(sr, s21_mult_number_suite());
  srunner_add_suite(sr, s21_mult_matrix_suite());
  srunner_add_suite(sr, s21_determinant_suite());
  srunner_add_suite(sr, s21_calc_complements_suite());
  srunner_add_suite(sr, s21_inverse_matrix_suite());

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? 1 : 0;
}