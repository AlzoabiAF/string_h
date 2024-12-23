#ifndef TEST_S21_STRING_
#define TEST_S21_STRING_

#include <check.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

TCase *s21_test_memchr(void);
TCase *s21_test_memcmp(void);
TCase *s21_test_memcpy(void);
TCase *s21_test_memset(void);
TCase *s21_test_strchr(void);
TCase *s21_test_strcspn(void);
TCase *s21_test_strerror(void);
TCase *s21_test_strlen(void);
TCase *s21_test_strncat(void);
TCase *s21_test_strncmp(void);
TCase *s21_test_strncpy(void);
TCase *s21_test_strpbrk(void);
TCase *s21_test_strrchr(void);
TCase *s21_test_strstr(void);
TCase *s21_test_strtok(void);
TCase *s21_test_insert(void);
TCase *s21_test_to_lower(void);
TCase *s21_test_to_upper(void);
TCase *s21_test_trim(void);
TCase *s21_test_sprintf(void);

#endif