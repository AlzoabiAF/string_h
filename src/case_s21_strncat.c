#include "test_s21_string.h"

START_TEST(test_1) {
  const char src[] = "world";
  char dest1[20] = {0}, dest2[20] = {0};
  printf("%s\n%s", dest1, dest2);
  strncat(dest1, src, 5);
  s21_strncat(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_2) {
  const char src[] = "world!";
  char dest1[20] = "Hello, ", dest2[20] = "Hello, ";
  strncat(dest1, src, 6);
  s21_strncat(dest2, src, 6);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_3) {
  const char src[] = "world";
  char *dest1 = calloc(10, sizeof(char)), *dest2 = calloc(10, sizeof(char));
  strncat(dest1, src, 5);
  s21_strncat(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_4) {
  const char src[] = "world";
  char *dest1 = calloc(10, sizeof(char)), *dest2 = calloc(10, sizeof(char));
  strncat(dest1, src, 5);
  s21_strncat(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_5) {
  const char src[] = "world";
  char *dest1 = calloc(4, sizeof(char)), *dest2 = calloc(4, sizeof(char));
  strncat(dest1, src, 3);
  s21_strncat(dest2, src, 3);
  ck_assert_str_eq(dest1, dest2);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_6) {
  const char src[] = "";
  char *dest1 = calloc(4, sizeof(char)), *dest2 = calloc(4, sizeof(char));
  strncat(dest1, src, 0);
  s21_strncat(dest2, src, 0);
  ck_assert_str_eq(dest1, dest2);
  free(dest1);
  free(dest2);
}
END_TEST

TCase *s21_test_strncat(void) {
  TCase *testCase = tcase_create("s21_strncat");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);

  return testCase;
}
