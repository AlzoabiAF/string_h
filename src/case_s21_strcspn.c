#include "test_s21_string.h"

START_TEST(test_1) {
  char str1[] = "hello world", str2[] = " ";
  int result1 = strcspn(str1, str2), result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_2) {
  char str1[] = "abcdef", str2[] = "x";
  int result1 = strcspn(str1, str2), result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_3) {
  char str1[] = "12345", str2[] = "345";
  int result1 = strcspn(str1, str2), result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_4) {
  char str1[] = "openAI", str2[] = "AI";
  int result1 = strcspn(str1, str2), result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_5) {
  char str1[] = "", str2[] = "abc";
  int result1 = strcspn(str1, str2), result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_6) {
  char str1[] = "abcdef", str2[] = "";
  int result1 = strcspn(str1, str2), result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_7) {
  char str1[] = "find_first", str2[] = "z";
  int result1 = strcspn(str1, str2), result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_8) {
  char str1[] = "beginning_of_string", str2[] = "b";
  int result1 = strcspn(str1, str2), result2 = s21_strcspn(str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

TCase *s21_test_strcspn(void) {
  TCase *testCase = tcase_create("s21_strcspn");

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
