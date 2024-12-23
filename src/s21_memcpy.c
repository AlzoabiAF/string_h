#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  void *res = S21_NULL;

  if (dest != S21_NULL && src != S21_NULL) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    s21_size_t i = 0;

    while (i < n) {
      d[i] = s[i];
      i++;
    }

    res = dest;
  }

  return res;
}
