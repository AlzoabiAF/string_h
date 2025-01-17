#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t i = 0;

    while (str[i] != '\0' && res == S21_NULL) {
      if (str[i] == (char)c) {
        res = (char *)(str + i);
      }

      i++;
    }

    if (c == '\0' && res == S21_NULL) {
      res = (char *)(str + s21_strlen(str));
    }
  }

  return res;
}
