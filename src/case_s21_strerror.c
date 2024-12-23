#include <errno.h>

#include "test_s21_string.h"

START_TEST(test_1) {
  int err = EINVAL;
  char *result1 = strerror(err), *result2 = s21_strerror(err);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_2) {
  int err = ENOMEM;
  char *result1 = strerror(err), *result2 = s21_strerror(err);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_3) {
  int err = EPERM;
  char *result1 = strerror(err), *result2 = s21_strerror(err);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_4) {
  int err = ENOENT;
  char *result1 = strerror(err), *result2 = s21_strerror(err);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_5) {
  int err = EIO;
  char *result1 = strerror(err), *result2 = s21_strerror(err);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_6) {
  int err = 0;  // No error
  char *result1 = strerror(err), *result2 = s21_strerror(err);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_7) {
  int err = 9999;  // Invalid error code
  char *result1 = strerror(err), *result2 = s21_strerror(err);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_8) {
  int err = EACCES;
  char *result1 = strerror(err), *result2 = s21_strerror(err);
  ck_assert_str_eq(result1, result2);
}
END_TEST

TCase *s21_test_strerror(void) {
  TCase *testCase = tcase_create("s21_strerror");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);
  tcase_add_test(testCase, test_7);
  tcase_add_test(testCase, test_8);

  return testCase;
}
