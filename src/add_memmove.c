#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  void *res = S21_NULL;

  if (dest != S21_NULL && src != S21_NULL) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    s21_size_t i = 0;

    if (d < s) {
      while (i < n) {
        d[i] = s[i];
        i++;
      }
    } else if (d > s) {
      i = n;
      while (i > 0) {
        d[i - 1] = s[i - 1];
        i--;
      }
    }

    res = dest;
  }

  return res;
}
