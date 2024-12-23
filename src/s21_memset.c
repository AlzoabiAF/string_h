#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  void *resi = S21_NULL;

  if (str != S21_NULL) {
    char *res = (char *)str;
    s21_size_t i = 0;

    while (i < n) {
      res[i] = (char)c;
      i++;
    }

    resi = res;
  }

  return resi;
}
