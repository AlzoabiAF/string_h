#include "test_s21_string.h"

START_TEST(test_1) {
  char str[] = "hello";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_2) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_3) {
  char str[] = "1234567890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_4) {
  char str[] = "string with spaces and\nline demolition";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_5) {
  char str[] = "Hello, World! our KFC team";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_6) {
  char str[] = "a\0b";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_7) {
  char str[] = "12345\0test";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_8) {
  char str[] = "\0check\0situation";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

TCase *s21_test_strlen(void) {
  TCase *testCase = tcase_create("s21_strlen");

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
