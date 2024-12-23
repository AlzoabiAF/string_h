#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = S21_NULL;

  if (str) {
    const unsigned char *s = (const unsigned char *)str;
    s21_size_t i = 0;

    while (i < n && res == S21_NULL) {
      if (s[i] == (unsigned char)c) {
        res = (void *)(s + i);
      }

      i++;
    }
  }

  return res;
}
