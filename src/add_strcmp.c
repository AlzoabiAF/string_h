#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;

  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }

  res = (unsigned char)*str1 - (unsigned char)*str2;
  return res;
}
