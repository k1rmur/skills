#include <check.h>
#include <stdio.h>

#include "s21_calc.h"

START_TEST(s21_test_destroy_1) {
  char *str = parse("log(x)/0", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_2) {
  char *str = parse("log(log12)", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_3) {
  char *str = parse("mod/2", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_4) {
  char *str = parse("atg(-1)", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_5) {
  char *str = parse("asin(100)", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_6) {
  char *str = parse("3^cos(-100))", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_7) {
  char *str = parse("sqrt(-1)", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_8) {
  char *str = parse("0.atan(1)+atg(-1)", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_9) {
  char *str = parse("acos2", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_10) {
  char *str = parse("ason(2131123)", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_11) {
  char *str = parse("sin1", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_12) {
  char *str = parse("fmid(2)", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_13) {
  char *str = parse("0..1", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_destroy_14) {
  char *str = parse("ln(-)", 1);
  ck_assert_str_eq(str, "Wrong");
  free(str);
}
END_TEST

START_TEST(s21_test_cos_1) {
  char str_core[255];
  double k = cos(3);
  char *str = parse("cos(3)", 1);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_cos_2) {
  char str_core[255];
  double k = cos(pow(3, 4) / 66);
  char *str = parse("cos(3^4/66)", 1);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_cos_3) {
  char str_core[255];
  double k = cos(-7 + 22);
  char *str = parse("cos(-7+22)", 1);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_cos_4) {
  char str_core[255];
  double k = acos(0.22);
  char *str = parse("acos(0.22)", 1);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_cos_5) {
  char str_core[255];
  double k = acos(0.22) / acos(0.1);
  char *str = parse("acos(0.22)/acos(0.1)", 1);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_cos_6) {
  char str_core[255];
  double k = acos(0.999) + acos(0.001 - 0.2);
  char *str = parse("acos(0.999)+acos(0.001-0.2)", 1);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

Suite *s21_cos_acos_suite(void) {
  TCase *tc = tcase_create("s21_cos_acos_core");
  Suite *s = suite_create("s21_cos_acos");

  tcase_add_test(tc, s21_test_cos_1);
  tcase_add_test(tc, s21_test_cos_2);
  tcase_add_test(tc, s21_test_cos_3);
  tcase_add_test(tc, s21_test_cos_4);
  tcase_add_test(tc, s21_test_cos_5);
  tcase_add_test(tc, s21_test_cos_6);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(s21_test_sin_asin_1) {
  char str_core[255];
  double k = sin(3 * 2);
  char *str = parse("sin(3*x)", 2);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_sin_asin_2) {
  char str_core[255];
  double k = sin(3 * (-4) - sin(1));
  char *str = parse("sin(3*(-4)-sin(1))", 2);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_sin_asin_3) {
  char str_core[255];
  double k = sin(111) - sin(112) + sin(0.0001);
  char *str = parse("sin(111)-sin(112)+sin(0.0001)", 2);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_sin_asin_4) {
  char str_core[255];
  double k = sin(1 - (-sin(sin(1))));
  char *str = parse("sin(1-(-sin(sin(1))))", 2);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_sin_asin_5) {
  char str_core[255];
  double k = -asin(0.00099);
  char *str = parse("-asin(0.00099)", 2);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_sin_asin_6) {
  char str_core[255];
  double k = -asin(asin(0.01 + asin(0.05)));
  char *str = parse("-asin(asin(0.01+asin(0.05)))", 2);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_sin_asin_7) {
  char str_core[255];
  double k = -asin(+asin(asin(asin(0.09))));
  char *str = parse("-asin(+asin(asin(asin(0.09))))", 2);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

Suite *s21_sin_asin_suite(void) {
  TCase *tc = tcase_create("s21_sin_core");
  Suite *s = suite_create("s21_sin_asin");

  tcase_add_test(tc, s21_test_sin_asin_1);
  tcase_add_test(tc, s21_test_sin_asin_2);
  tcase_add_test(tc, s21_test_sin_asin_3);
  tcase_add_test(tc, s21_test_sin_asin_4);
  tcase_add_test(tc, s21_test_sin_asin_5);
  tcase_add_test(tc, s21_test_sin_asin_6);
  tcase_add_test(tc, s21_test_sin_asin_7);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(s21_test_tan_atan_1) {
  char str_core[255];
  double k = tan(3 - 1);
  char *str = parse("tan(3-1)", 1);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_tan_atan_2) {
  char str_core[255];
  double k = tan(1);
  char *str = parse("tan(x)", 1);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_tan_atan_3) {
  char str_core[255];
  double k = tan(pow(2, 3) + tan(2));
  char *str = parse("tan(2^x+tan(2))", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_tan_atan_4) {
  char str_core[255];
  double k = atan(0.2 * atan(1));
  char *str = parse("atan(0.2*atan(1))", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_tan_atan_5) {
  char str_core[255];
  double k = atan(+atan(-atan(0.01)));
  char *str = parse("atan(+atan(-atan(0.01)))", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_test_tan_atan_6) {
  char str_core[255];
  double k = atan(+atan(-atan(0.1 + atan(0.001))));
  char *str = parse("atan(+atan(-atan(0.1+atan(0.001))))", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

Suite *s21_tan_atan_suite(void) {
  TCase *tc = tcase_create("s21_tan_core");
  Suite *s = suite_create("s21_tan_atan");

  tcase_add_test(tc, s21_test_tan_atan_1);
  tcase_add_test(tc, s21_test_tan_atan_2);
  tcase_add_test(tc, s21_test_tan_atan_3);
  tcase_add_test(tc, s21_test_tan_atan_4);
  tcase_add_test(tc, s21_test_tan_atan_5);
  tcase_add_test(tc, s21_test_tan_atan_6);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(s21_log_mod_1) {
  char str_core[255];
  double k = log(2 + 13.3) + 4 / 2 + pow(4, 4);
  char *str = parse("log(2+13.3)+x/2+x^x", 4);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_log_mod_2) {
  char str_core[255];
  double k = log(log(6) - 0.2);
  char *str = parse("log(log(6)-0.2)", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_log_mod_3) {
  char str_core[255];
  double k = fmod(5, 1) + fmod(1, 1);
  char *str = parse("5mod1+1mod1", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_log_mod_4) {
  char str_core[255];
  double k = fmod(5, log10(10));
  char *str = parse("5mod(ln(10))", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_log_mod_5) {
  char str_core[255];
  double k = log10(11) + fmod(999, 111);
  char *str = parse("ln(11)+999mod111", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_log_mod_6) {
  char str_core[255];
  double k = log10(12) + fmod(2, 1);
  char *str = parse("ln(12)+2mod1", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_general_1) {
  char str_core[255];
  double k = sqrt(cos(sin(1))) - atan(-2 * 3.3 + 32);
  char *str = parse("sqrt(cos(sin(1)))-atan(-2*x+32)", 3.3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_general_2) {
  char str_core[255];
  double k = log10(cos(-1 + atan(cos(1))));
  char *str = parse("ln(cos(-1+atan(cos(1))))", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_general_3) {
  char str_core[255];
  double k = pow(cos(1), 11) - asin(0.99) - atan(2);
  char *str = parse("cos(1)^11-asin(0.99)-atan(2)", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_general_4) {
  char str_core[255];
  double k = -1 - (-1 - (-1 + (+1 + (+1))));
  char *str = parse("-1-(-1-(-1+(+1+(+1))))", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

START_TEST(s21_general_5) {
  char str_core[255];
  double k = atan(-1.1111 - cos(2.1112)) + sqrt(cos(11));
  char *str = parse("atan(-1.1111-cos(2.1112))+sqrt(cos(11))", 3);
  sprintf(str_core, "%f", k);
  ck_assert_str_eq(str, str_core);
  free(str);
}
END_TEST

Suite *s21_general_suite(void) {
  TCase *tc = tcase_create("s21_general_core");
  Suite *s = suite_create("s21_general");

  tcase_add_test(tc, s21_general_1);
  tcase_add_test(tc, s21_general_2);
  tcase_add_test(tc, s21_general_3);
  tcase_add_test(tc, s21_general_4);
  tcase_add_test(tc, s21_general_5);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_log_mod_suite(void) {
  TCase *tc = tcase_create("s21_log_mod_core");
  Suite *s = suite_create("s21_log_mod");

  tcase_add_test(tc, s21_log_mod_1);
  tcase_add_test(tc, s21_log_mod_2);
  tcase_add_test(tc, s21_log_mod_3);
  tcase_add_test(tc, s21_log_mod_4);
  tcase_add_test(tc, s21_log_mod_5);
  tcase_add_test(tc, s21_log_mod_6);

  suite_add_tcase(s, tc);
  return s;
}

Suite *s21_test_suite(void) {
  TCase *tc = tcase_create("s21_test_core");
  Suite *s = suite_create("s21_test");

  tcase_add_test(tc, s21_test_destroy_1);
  tcase_add_test(tc, s21_test_destroy_2);
  tcase_add_test(tc, s21_test_destroy_3);
  tcase_add_test(tc, s21_test_destroy_4);
  tcase_add_test(tc, s21_test_destroy_5);
  tcase_add_test(tc, s21_test_destroy_6);
  tcase_add_test(tc, s21_test_destroy_7);
  tcase_add_test(tc, s21_test_destroy_8);
  tcase_add_test(tc, s21_test_destroy_9);
  tcase_add_test(tc, s21_test_destroy_10);
  tcase_add_test(tc, s21_test_destroy_11);
  tcase_add_test(tc, s21_test_destroy_12);
  tcase_add_test(tc, s21_test_destroy_13);
  tcase_add_test(tc, s21_test_destroy_14);

  suite_add_tcase(s, tc);
  return s;
}

int main() {
  int failed = 0;
  SRunner *sr;

  sr = srunner_create(s21_test_suite());
  srunner_add_suite(sr, s21_cos_acos_suite());
  srunner_add_suite(sr, s21_sin_asin_suite());
  srunner_add_suite(sr, s21_tan_atan_suite());
  srunner_add_suite(sr, s21_log_mod_suite());
  srunner_add_suite(sr, s21_general_suite());

  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failed == 0) ? 1 : 0;
}
