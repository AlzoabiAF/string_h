#include "test_s21_string.h"

START_TEST(test_1) {
  char src[] = "world", *result1 = strchr(src, 'o'),
       *result2 = s21_strchr(src, 'o');
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_2) {
  char src[] = "hello world!", *result1 = strchr(src, '!'),
       *result2 = s21_strchr(src, '!');
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_3) {
  char src[] = "world", *result1 = strchr(src, 'z'),
       *result2 = s21_strchr(src, 'z');
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_4) {
  char src[] = "", *result1 = strchr(src, 'a'), *result2 = s21_strchr(src, 'a');
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_5) {
  char src[] = "world", *result1 = strchr(src, 'w'),
       *result2 = s21_strchr(src, 'w');
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_6) {
  char src[] = "a quick brown fox", *result1 = strchr(src, 'b'),
       *result2 = s21_strchr(src, 'b');
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

TCase *s21_test_strchr(void) {
  TCase *testCase = tcase_create("s21_strchr");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);

  return testCase;
}
