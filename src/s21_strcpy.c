#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *res = S21_NULL;

  if (dest != S21_NULL && src != S21_NULL) {
    s21_size_t i = 0;

    while (src[i] != '\0') {
      dest[i] = src[i];
      i++;
    }

    dest[i] = '\0';
    res = dest;
  }

  return res;
}
