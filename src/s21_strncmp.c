#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i = 0;

  while (i < n && res == 0) {
    unsigned char c1 = (unsigned char)str1[i], c2 = (unsigned char)str2[i];

    if (c1 != c2) {
      res = c1 - c2;
    }

    if (c1 == '\0' || c2 == '\0') {
      break;
    }

    i++;
  }

  return res;
}
