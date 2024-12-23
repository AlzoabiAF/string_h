#include "test_s21_string.h"

START_TEST(test_1) {
  const char src[] = "hello";
  char dest1[20] = {0}, dest2[20] = {0};
  strncpy(dest1, src, 5);
  s21_strncpy(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_2) {
  const char src[] = "";
  char dest1[20] = {0}, dest2[20] = {0};
  strncpy(dest1, src, 1);
  s21_strncpy(dest2, src, 1);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_3) {
  const char src[] = "world";
  char dest1[10] = {0}, dest2[10] = {0};
  strncpy(dest1, src, 5);
  s21_strncpy(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_4) {
  const char src[] = "Hello, world!";
  char dest1[20] = {0}, dest2[20] = {0};
  strncpy(dest1, src, 13);
  s21_strncpy(dest2, src, 13);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_5) {
  const char src[] = "abc";
  char dest1[20] = "12345", dest2[20] = "12345";
  strncpy(dest1, src, 3);
  s21_strncpy(dest2, src, 3);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_6) {
  const char src[] = "adada\0adasdasd";
  char dest1[20] = {0}, dest2[20] = {0};
  strncpy(dest1, src, 5);
  s21_strncpy(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_7) {
  const char src[] = "!@#$%^&*()";
  char *dest1 = calloc(50, sizeof(char)), *dest2 = calloc(50, sizeof(char));
  strncpy(dest1, src, 10);
  s21_strncpy(dest2, src, 10);
  ck_assert_str_eq(dest1, dest2);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_8) {
  const char src[] = "short";
  char *dest1 = calloc(5, sizeof(char)), *dest2 = calloc(5, sizeof(char));
  strncpy(dest1, src, 5);
  s21_strncpy(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
  free(dest1);
  free(dest2);
}
END_TEST

TCase *s21_test_strncpy(void) {
  TCase *testCase = tcase_create("s21_strncpy");

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
