#include "test_s21_string.h"

START_TEST(test_1) {
  char *data = "Hello, world!", check_symbol = 'd';
  ck_assert_ptr_eq(memchr(data, check_symbol, strlen(data) + 1),
                   s21_memchr(data, check_symbol, s21_strlen(data) + 1));
}
END_TEST

START_TEST(test_2) {
  char *data = "", check_symbol = 'd';
  ck_assert_ptr_eq(memchr(data, check_symbol, strlen(data) + 1),
                   s21_memchr(data, check_symbol, s21_strlen(data) + 1));
}
END_TEST

START_TEST(test_3) {
  char *data = "ASDASDSASaaaa", check_symbol = 'S';
  ck_assert_ptr_eq(memchr(data, check_symbol, strlen(data) + 1),
                   s21_memchr(data, check_symbol, s21_strlen(data) + 1));
}
END_TEST

START_TEST(test_4) {
  char *data = "test1234test", check_symbol = '\0';
  ck_assert_ptr_eq(memchr(data, check_symbol, strlen(data) + 1),
                   s21_memchr(data, check_symbol, s21_strlen(data) + 1));
}
END_TEST

START_TEST(test_5) {
  char *data = "", check_symbol = 's';
  ck_assert_ptr_eq(memchr(data, check_symbol, strlen(data) + 1),
                   s21_memchr(data, check_symbol, s21_strlen(data) + 1));
}
END_TEST

START_TEST(test_6) {
  char *data = "", check_symbol = '\0';
  ck_assert_ptr_eq(memchr(data, check_symbol, strlen(data) + 1),
                   s21_memchr(data, check_symbol, s21_strlen(data) + 1));
}
END_TEST

TCase *s21_test_memchr(void) {
  TCase *testCase = tcase_create("s21_memchr");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);

  return testCase;
}
