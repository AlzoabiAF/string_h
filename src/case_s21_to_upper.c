#include "test_s21_string.h"

START_TEST(test_1) {
  const char str[] = "hello";
  char *result = s21_to_upper(str);
  char expected[] = "HELLO";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_2) {
  const char str[] = "world!";
  char *result = s21_to_upper(str);
  char expected[] = "WORLD!";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_3) {
  const char str[] = "TeSt123";
  char *result = s21_to_upper(str);
  char expected[] = "TEST123";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_5) {
  const char str[] = "HELLO WORLD!";
  char *result = s21_to_upper(str);
  char expected[] = "HELLO WORLD!";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_6) {
  const char str[] = "12345";
  char *result = s21_to_upper(str);
  char expected[] = "12345";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_7) {
  const char str[] = "!@#$%^&*()";
  char *result = s21_to_upper(str);
  char expected[] = "!@#$%^&*()";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_8) {
  const char str[] = "";
  char *result = s21_to_upper(str);
  char expected[] = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

TCase *s21_test_to_upper(void) {
  TCase *testCase = tcase_create("s21_to_upper");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);
  tcase_add_test(testCase, test_7);
  tcase_add_test(testCase, test_8);

  return testCase;
}