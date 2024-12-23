#include "test_s21_string.h"

START_TEST(test_1) {
  const char str[] = "hello", ch = 'o';
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(test_2) {
  const char str[] = "abcdef", ch = 'd';
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(test_3) {
  const char str[] = "hello world", ch = 'l';
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(test_4) {
  const char str[] = "hello", ch = 'z';
  ck_assert_ptr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(test_5) {
  const char str[] = "apple", ch = 'p';
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(test_6) {
  const char str[] = "abcdefg", ch = 'g';
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(test_7) {
  const char str[] = "abcdabcd", ch = 'a';
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(test_8) {
  const char str[] = "abcdefgh", ch = 'h';
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

TCase *s21_test_strrchr(void) {
  TCase *testCase = tcase_create("s21_strrchr");

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
