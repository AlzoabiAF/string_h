#include "test_s21_string.h"

START_TEST(test_1) {
  char src[] = "hello", insert[] = " world";
  char *result = s21_insert(src, insert, 5);
  char expected[] = "hello world";
  ck_assert_str_eq(result, expected);
  free(result);  // Освобождаем память, выделенную функцией
}
END_TEST

START_TEST(test_2) {
  char src[] = "apple", insert[] = " pie";
  char *result = s21_insert(src, insert, 5);
  char expected[] = "apple pie";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_3) {
  char src[] = "abcdef", insert[] = "gh";
  char *result = s21_insert(src, insert, 6);
  char expected[] = "abcdefgh";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_5) {
  char src[] = "12345", insert[] = "67890";
  char *result = s21_insert(src, insert, 5);
  char expected[] = "1234567890";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_6) {
  char src[] = "apple pie", insert[] = " is tasty";
  char *result = s21_insert(src, insert, 9);
  char expected[] = "apple pie is tasty";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_7) {
  char src[] = "hello", insert[] = "world";
  char *result = s21_insert(src, insert, 5);
  char expected[] = "helloworld";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_8) {
  char str[50] = "test", insert[] = "";
  s21_insert(str, insert, 2);
  char expected[] = "test";
  ck_assert_str_eq(str, expected);
}
END_TEST

TCase *s21_test_insert(void) {
  TCase *testCase = tcase_create("s21_insert");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);
  tcase_add_test(testCase, test_7);
  tcase_add_test(testCase, test_8);

  return testCase;
}