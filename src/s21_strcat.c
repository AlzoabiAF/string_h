#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *res = S21_NULL;

  if (dest != S21_NULL && src != S21_NULL) {
    s21_size_t i = 0;
    while (dest[i] != '\0') {
      i++;
    }

    s21_size_t j = 0;
    while (src[j] != '\0') {
      dest[i++] = src[j++];
    }

    dest[i] = '\0';
    res = dest;
  }

  return res;
}
