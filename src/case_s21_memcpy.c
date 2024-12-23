#include "test_s21_string.h"

START_TEST(test_1) {
  char *src = "Hello, world!", dest1[20], dest2[20];
  int ln = s21_strlen(src) + 1;
  memcpy(dest1, src, ln);
  s21_memcpy(dest2, src, ln);
  ck_assert_mem_eq(dest1, dest2, ln);
}
END_TEST

START_TEST(test_2) {
  char *src = "1234567890123456789012345", dest1[20], dest2[20];
  int ln = s21_strlen(src) + 1;
  memcpy(dest1, src, ln);
  s21_memcpy(dest2, src, ln);
  ck_assert_mem_eq(dest1, dest2, ln);
}
END_TEST

START_TEST(test_3) {
  char *src = "Hello, world!", *dest1 = malloc(sizeof(char) * 20),
       *dest2 = malloc(sizeof(char) * 20);
  int ln = s21_strlen(src) + 1;
  memcpy(dest1, src, ln);
  s21_memcpy(dest2, src, ln);
  ck_assert_mem_eq(dest1, dest2, ln);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_4) {
  char src[10] = {0}, *dest1 = malloc(sizeof(char) * 10),
       *dest2 = malloc(sizeof(char) * 10);
  int ln = s21_strlen(src) + 1;
  memcpy(dest1, src, ln);
  s21_memcpy(dest2, src, ln);
  ck_assert_mem_eq(dest1, dest2, ln);
  free(dest1);
  free(dest2);
}
END_TEST

TCase *s21_test_memcpy(void) {
  TCase *testCase = tcase_create("s21_memcpy");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);

  return testCase;
}
