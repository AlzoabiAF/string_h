#include "test_s21_string.h"

START_TEST(test_1) {
  char str[] = "hello", accept[] = "aeiou";
  ck_assert_ptr_eq(strpbrk(str, accept), s21_strpbrk(str, accept));
}
END_TEST

START_TEST(test_2) {
  char str[] = "abcdef", accept[] = "def";
  ck_assert_ptr_eq(strpbrk(str, accept), s21_strpbrk(str, accept));
}
END_TEST

START_TEST(test_3) {
  char str[] = "hello world", accept[] = " ";
  ck_assert_ptr_eq(strpbrk(str, accept), s21_strpbrk(str, accept));
}
END_TEST

START_TEST(test_4) {
  char str[] = "check", accept[] = "word";
  char *result1 = strpbrk(str, accept), *result2 = s21_strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_5) {
  char str[] = "1234567890", accept[] = "567";
  ck_assert_ptr_eq(strpbrk(str, accept), s21_strpbrk(str, accept));
}
END_TEST

START_TEST(test_6) {
  char str[] = "abcdefg", accept[] = "bcd";
  ck_assert_ptr_eq(strpbrk(str, accept), s21_strpbrk(str, accept));
}
END_TEST

START_TEST(test_7) {
  char str[] = "abcdefgh", accept[] = "gh";
  ck_assert_ptr_eq(strpbrk(str, accept), s21_strpbrk(str, accept));
}
END_TEST

START_TEST(test_8) {
  char str[] = "xyz", accept[] = "abc";
  ck_assert_ptr_eq(strpbrk(str, accept), s21_strpbrk(str, accept));
}
END_TEST

TCase *s21_test_strpbrk(void) {
  TCase *testCase = tcase_create("s21_strpbrk");

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
