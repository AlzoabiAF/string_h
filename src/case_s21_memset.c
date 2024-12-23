#include "test_s21_string.h"

START_TEST(test_1) {
  char buffer1[10];
  char buffer2[10];
  int fill_char = 'A';

  memset(buffer1, fill_char, sizeof(buffer1));
  s21_memset(buffer2, fill_char, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(test_2) {
  char buffer1[10];
  char buffer2[10];
  int fill_char = ' ';

  memset(buffer1, fill_char, sizeof(buffer1));
  s21_memset(buffer2, fill_char, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(test_3) {
  char buffer1[10];
  char buffer2[10];
  int fill_char = '\n';

  memset(buffer1, fill_char, sizeof(buffer1));
  s21_memset(buffer2, fill_char, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(test_4) {
  char buffer1[10];
  char buffer2[10];
  int fill_char = '\t';

  memset(buffer1, fill_char, sizeof(buffer1));
  s21_memset(buffer2, fill_char, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(test_5) {
  char buffer1[10];
  char buffer2[10];
  int fill_char = '\0';

  memset(buffer1, fill_char, sizeof(buffer1));
  s21_memset(buffer2, fill_char, sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));
}
END_TEST

START_TEST(test_6) {
  char *buffer1 = malloc(sizeof(char) * 10);
  char *buffer2 = malloc(sizeof(char) * 10);
  int fill_char = ' ';

  memset(buffer1, fill_char, (size_t)sizeof(buffer1));
  s21_memset(buffer2, fill_char, (size_t)sizeof(buffer2));

  ck_assert_mem_eq(buffer1, buffer2, (size_t)sizeof(buffer1));
  free(buffer1);
  free(buffer2);
}
END_TEST

TCase *s21_test_memset(void) {
  TCase *testCase = tcase_create("s21_memset");

  tcase_add_test(testCase, test_1);
  tcase_add_test(testCase, test_2);
  tcase_add_test(testCase, test_3);
  tcase_add_test(testCase, test_4);
  tcase_add_test(testCase, test_5);
  tcase_add_test(testCase, test_6);

  return testCase;
}
