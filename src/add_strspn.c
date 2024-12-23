#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    s21_size_t i = 0;
    while (str1[i] != '\0') {
      bool match_found = false;
      s21_size_t j = 0;

      while (str2[j] != '\0' && !match_found) {
        if (str1[i] == str2[j++]) {
          match_found = true;
        }
      }

      if (match_found) {
        res++;
      } else {
        break;
      }

      i++;
    }
  }

  return res;
}
