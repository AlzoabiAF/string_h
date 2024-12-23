#include "test_s21_string.h"

START_TEST(test_1) {
  const char str[] = "HELLO";
  char *result = s21_to_lower(str);
  char expected[] = "hello";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_2) {
  const char str[] = "WORLD!";
  char *result = s21_to_lower(str);
  char expected[] = "world!";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_3) {
  const char str[] = "TeSt123";
  char *result = s21_to_lower(str);
  char expected[] = "test123";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_4) {
  const char str[] = "AbCdEfGh";
  char *result = s21_to_lower(str);
  char expected[] = "abcdefgh";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_5) {
  const char str[] = "hello world!";
  char *result = s21_to_lower(str);
  char expected[] = "hello world!";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_6) {
  const char str[] = "12345";
  char *result = s21_to_lower(str);
  char expected[] = "12345";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_7) {
  const char str[] = "!@#$%^&*()";
  char *result = s21_to_lower(str);
  char expected[] = "!@#$%^&*()";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_8) {
  const char str[] = "";
  char *result = s21_to_lower(str);
  char expected[] = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

TCase *s21_test_to_lower(void) {
  TCase *testCase = tcase_create("s21_to_lower");

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