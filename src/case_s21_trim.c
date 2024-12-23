#include "test_s21_string.h"

START_TEST(test_1) {
  const char str[] = "   hello   ";
  char *result = s21_trim(str, " ");
  char expected[] = "hello";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_2) {
  const char str[] = "!!hello!!";
  char *result = s21_trim(str, "!");
  char expected[] = "hello";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_3) {
  const char str[] = "   hello world   ";
  char *result = s21_trim(str, " ");
  char expected[] = "hello world";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_4) {
  const char str[] = "***hello***";
  char *result = s21_trim(str, "*");
  char expected[] = "hello";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_5) {
  const char str[] = "abc123abc";
  char *result = s21_trim(str, "abc");
  char expected[] = "123";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_6) {
  const char str[] = "no trimming needed";
  char *result = s21_trim(str, " ");
  char expected[] = "no trimming needed";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_7) {
  const char str[] = "     ";
  char *result = s21_trim(str, " ");
  char expected[] = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_8) {
  const char str[] = "";
  char *result = s21_trim(str, " ");
  char expected[] = "";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_9) {
  const char str[] = "   привет   ";
  char *result = s21_trim(str, " ");
  char expected[] = "привет";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_10) {
  const char str[] = "///здравствуйте///";
  char *result = s21_trim(str, "/");
  char expected[] = "здравствуйте";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_11) {
  const char str[] = "   доброе утро   ";
  char *result = s21_trim(str, " ");
  char expected[] = "доброе утро";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_12) {
  const char str[] = "!!!добрый вечер!!!";
  char *result = s21_trim(str, "!");
  char expected[] = "добрый вечер";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_13) {
  const char str[] = "привет, мир";
  char *result = s21_trim(str, " ");
  char expected[] = "привет, мир";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_14) {
  const char str[] = "абв123абв";
  char *result = s21_trim(str, "абв");
  char expected[] = "123";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

TCase *s21_test_trim(void) {
  TCase *testCase = tcase_create("s21_trim");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);
  tcase_add_test(testCase, test_7);
  tcase_add_test(testCase, test_8);
  tcase_add_test(testCase, test_9);
  tcase_add_test(testCase, test_10);
  tcase_add_test(testCase, test_11);
  tcase_add_test(testCase, test_12);
  tcase_add_test(testCase, test_13);
  tcase_add_test(testCase, test_14);

  return testCase;
}