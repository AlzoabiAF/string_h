#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *res = S21_NULL;

  if (dest != S21_NULL && src != S21_NULL) {
    s21_size_t i = 0;

    while (i < n) {
      dest[i] = (src[i] != '\0') ? src[i] : '\0';
      i++;
    }

    res = dest;
  }

  return res;
}
