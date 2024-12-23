#include "test_s21_string.h"

int main(void) {
  int failed = 0;
  Suite *suite_s21_string = suite_create("s21_string.h");

  suite_add_tcase(suite_s21_string, s21_test_memchr());
  suite_add_tcase(suite_s21_string, s21_test_memcmp());
  suite_add_tcase(suite_s21_string, s21_test_memcpy());
  suite_add_tcase(suite_s21_string, s21_test_memset());
  suite_add_tcase(suite_s21_string, s21_test_strchr());
  suite_add_tcase(suite_s21_string, s21_test_strcspn());
  suite_add_tcase(suite_s21_string, s21_test_strerror());
  suite_add_tcase(suite_s21_string, s21_test_strlen());
  suite_add_tcase(suite_s21_string, s21_test_strncat());
  suite_add_tcase(suite_s21_string, s21_test_strncmp());
  suite_add_tcase(suite_s21_string, s21_test_strncpy());
  suite_add_tcase(suite_s21_string, s21_test_strpbrk());
  suite_add_tcase(suite_s21_string, s21_test_strrchr());
  suite_add_tcase(suite_s21_string, s21_test_strstr());
  suite_add_tcase(suite_s21_string, s21_test_strtok());
  suite_add_tcase(suite_s21_string, s21_test_insert());
  suite_add_tcase(suite_s21_string, s21_test_to_upper());
  suite_add_tcase(suite_s21_string, s21_test_to_lower());
  suite_add_tcase(suite_s21_string, s21_test_trim());
  suite_add_tcase(suite_s21_string, s21_test_sprintf());
  SRunner *runner = srunner_create(suite_s21_string);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? 0 : 1;
}
