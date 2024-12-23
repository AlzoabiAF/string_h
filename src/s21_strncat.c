#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *res = S21_NULL;

  if (dest != S21_NULL && src != S21_NULL) {
    s21_size_t dest_len = s21_strlen(dest), src_len = s21_strlen(src), i = 0;
    n = (n > src_len) ? src_len : n;

    while (i < n) {
      dest[dest_len + i] = src[i];
      i++;
    }

    dest[dest_len + n] = '\0';
    res = dest;
  }

  return res;
}
