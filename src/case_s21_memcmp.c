#include "test_s21_string.h"

START_TEST(test_1) {
  char *data1 = "Hello", *data2 = "Hello";
  int countSymbol = 5;
  ck_assert_int_eq(memcmp(data1, data2, countSymbol),
                   s21_memcmp(data1, data2, countSymbol));
}
END_TEST

START_TEST(test_2) {
  char *data1 = "Hello", *data2 = "Hella";
  int countSymbol = 5;
  ck_assert_int_eq(memcmp(data1, data2, countSymbol),
                   s21_memcmp(data1, data2, countSymbol));
}
END_TEST

START_TEST(test_3) {
  char *data1 = "Hello", *data2 = "Hella";
  int countSymbol = 0;
  ck_assert_int_eq(memcmp(data1, data2, countSymbol),
                   s21_memcmp(data1, data2, countSymbol));
}
END_TEST

START_TEST(test_4) {
  char *data1 = "Hello", *data2 = "Hella";
  int countSymbol = 3;
  ck_assert_int_eq(memcmp(data1, data2, countSymbol),
                   s21_memcmp(data1, data2, countSymbol));
}
END_TEST

START_TEST(test_5) {
  char *data1 = "Hello", *data2 = "Hella";
  int countSymbol = 6;
  ck_assert_int_eq(memcmp(data1, data2, countSymbol),
                   s21_memcmp(data1, data2, countSymbol));
}
END_TEST

START_TEST(test_6) {
  char *data1 = NULL, *data2 = "Hella";
  int countSymbol = 0;
  ck_assert_int_eq(memcmp(data1, data2, countSymbol),
                   s21_memcmp(data1, data2, countSymbol));
}
END_TEST

START_TEST(test_7) {
  char *data1 = "Hello", *data2 = NULL;
  int countSymbol = 0;
  ck_assert_int_eq(memcmp(data1, data2, countSymbol),
                   s21_memcmp(data1, data2, countSymbol));
}
END_TEST

START_TEST(test_8) {
  char *data1 = NULL, *data2 = NULL;
  int countSymbol = 0;
  ck_assert_int_eq(memcmp(data1, data2, countSymbol),
                   s21_memcmp(data1, data2, countSymbol));
}
END_TEST

TCase *s21_test_memcmp(void) {
  TCase *testCase = tcase_create("s21_memcmp");

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
