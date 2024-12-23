#include "test_s21_string.h"

START_TEST(test_1) {
  char str[] = "hello world", delim[] = " ";
  ck_assert_str_eq(strtok(str, delim), s21_strtok(str, delim));
}
END_TEST

START_TEST(test_2) {
  char str[] = "xaaxaxax.,adadasd,aewthf", delim[] = ",";
  ck_assert_str_eq(strtok(str, delim), s21_strtok(str, delim));
}
END_TEST

START_TEST(test_3) {
  char str[] = "this is a KFC", delim[] = " ";
  ck_assert_str_eq(strtok(str, delim), s21_strtok(str, delim));
}
END_TEST

START_TEST(test_4) {
  char str[] = "123-456-789", delim[] = "-";
  ck_assert_str_eq(strtok(str, delim), s21_strtok(str, delim));
}
END_TEST

START_TEST(test_5) {
  char str[] = "xaaxaxax; adadasd;aewthf", delim[] = ";";
  ck_assert_str_eq(strtok(str, delim), s21_strtok(str, delim));
}
END_TEST

START_TEST(test_6) {
  char str[] = "hello", delim[] = "";
  ck_assert_ptr_eq(strtok(str, delim), s21_strtok(str, delim));
}
END_TEST

// START_TEST(test_7) {
//   const char str[] = "hello world test", delim[] = " ";
//   strtok(str, delim);
//   s21_strtok(str, delim);
//   ck_assert_str_eq(strtok(NULL, delim), s21_strtok(NULL, delim));
// }
// END_TEST

START_TEST(test_8) {
  char str[] = "one\0two\0three\0four", delim[] = "\0";
  ck_assert_str_eq(strtok(str, delim), s21_strtok(str, delim));
}
END_TEST

TCase *s21_test_strtok(void) {
  TCase *testCase = tcase_create("s21_strtok");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);
  // tcase_add_test(testCase, test_7);
  tcase_add_test(testCase, test_8);

  return testCase;
}
