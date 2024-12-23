#include "test_s21_string.h"

START_TEST(test_1) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%s", "hello");
  sprintf(dest2, "%s", "hello");
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_2) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%d", 123);
  sprintf(dest2, "%d", 123);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_3) {
  const double pi = 3.14159;
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%f", pi);
  sprintf(dest2, "%f", pi);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_4) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%u", 429496729);
  sprintf(dest2, "%u", 429496729);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_5) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%c", 'A');
  sprintf(dest2, "%c", 'A');
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_6) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%d", -123);
  sprintf(dest2, "%d", -123);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_7) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%+d", 123);
  sprintf(dest2, "%+d", 123);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_8) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%d", -42);
  sprintf(dest2, "%d", -42);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_9) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%10d", 123);
  sprintf(dest2, "%10d", 123);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_10) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%-10d", 123);
  sprintf(dest2, "%-10d", 123);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_11) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%.2f", 3.14159);
  sprintf(dest2, "%.2f", 3.14159);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_12) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%10.2f", 3.14159);
  sprintf(dest2, "%10.2f", 3.14159);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_13) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%+10.2f", 3.14159);
  sprintf(dest2, "%+10.2f", 3.14159);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// START_TEST(test_14) {
//     char dest1[100], dest2[100];
//     s21_sprintf(dest1, "%010d", 123);
//     sprintf(dest2, "%010d", 123);
//     ck_assert_str_eq(dest1, dest2);
// }
// END_TEST

START_TEST(test_15) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%ld", 123456789L);
  sprintf(dest2, "%ld", 123456789L);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_16) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%hd", 12345);
  sprintf(dest2, "%hd", 12345);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_17) {
  char dest1[100], dest2[100];
  s21_sprintf(dest1, "%%");
  sprintf(dest2, "%%");
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

TCase *s21_test_sprintf(void) {
  TCase *testCase = tcase_create("s21_sprintf");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);
  tcase_add_test(testCase, test_7);
  tcase_add_test(testCase, test_8);
  tcase_add_test(testCase, test_9);
  tcase_add_test(testCase, test_10);
  tcase_add_test(testCase, test_11);
  tcase_add_test(testCase, test_12);
  tcase_add_test(testCase, test_13);
  // tcase_add_test(testCase, test_14);
  tcase_add_test(testCase, test_15);
  tcase_add_test(testCase, test_16);
  tcase_add_test(testCase, test_17);
  tcase_add_test(testCase, test_17);

  return testCase;
}