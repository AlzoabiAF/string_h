#include "test_s21_string.h"

START_TEST(test_1) {
  const char str1[] = "hello", str2[] = "hello";
  ck_assert_int_eq(strncmp(str1, str2, 5), s21_strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_2) {
  const char str1[] = "abc", str2[] = "abcd";
  ck_assert_int_eq(strncmp(str1, str2, 4), s21_strncmp(str1, str2, 4));
}
END_TEST

START_TEST(test_3) {
  const char str1[] = "abcd", str2[] = "abc";
  ck_assert_int_eq(strncmp(str1, str2, 4), s21_strncmp(str1, str2, 4));
}
END_TEST

START_TEST(test_4) {
  const char str1[] = "Русский", str2[] = "Русский";
  ck_assert_int_eq(strncmp(str1, str2, 7), s21_strncmp(str1, str2, 7));
}
END_TEST

START_TEST(test_5) {
  const char str1[] = "", str2[] = "";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

START_TEST(test_6) {
  const char str1[] = "hello", str2[] = "Hello";
  ck_assert_int_eq(strncmp(str1, str2, 5), s21_strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_7) {
  const char str1[] = "Русскиййй", str2[] = "Русский";
  ck_assert_int_eq(strncmp(str1, str2, 7), s21_strncmp(str1, str2, 7));
}
END_TEST

TCase *s21_test_strncmp(void) {
  TCase *testCase = tcase_create("s21_strncmp");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);
  tcase_add_test(testCase, test_7);

  return testCase;
}
