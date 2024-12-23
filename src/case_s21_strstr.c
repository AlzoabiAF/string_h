#include "test_s21_string.h"

START_TEST(test_1) {
  const char str[] = "hello", substr[] = "ll";
  ck_assert_str_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(test_2) {
  const char str[] = "abcdef", substr[] = "def";
  ck_assert_str_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(test_3) {
  const char str[] = "hello world", substr[] = "world";
  ck_assert_str_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(test_4) {
  const char str[] = "apple", substr[] = "xyz";
  ck_assert_ptr_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(test_5) {
  const char str[] = "1234567890", substr[] = "567";
  ck_assert_str_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(test_6) {
  const char str[] = "abcdefg", substr[] = "abc";
  ck_assert_str_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(test_7) {
  const char str[] = "abcdabcd", substr[] = "cd";
  ck_assert_str_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

START_TEST(test_8) {
  const char str[] = "abcdefgh", substr[] = "h";
  ck_assert_str_eq(strstr(str, substr), s21_strstr(str, substr));
}
END_TEST

TCase *s21_test_strstr(void) {
  TCase *testCase = tcase_create("s21_strstr");

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
