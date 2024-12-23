#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t i = 0;

    while (str[i] != '\0') {
      if (str[i] == c) {
        res = (char *)(str + i);
      }

      i++;
    }
  }

  return res;
}
