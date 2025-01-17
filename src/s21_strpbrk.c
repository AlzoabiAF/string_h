#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;

  if (str1 != S21_NULL && str2 != S21_NULL) {
    s21_size_t i = 0;

    while (str1[i] != '\0' && res == S21_NULL) {
      s21_size_t j = 0;

      while (str2[j] != '\0') {
        if (str1[i] == str2[j]) {
          res = (char *)(str1 + i);
          break;
        }

        j++;
      }

      i++;
    }
  }

  return res;
}
