#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;

  if (haystack != S21_NULL && needle != S21_NULL) {
    s21_size_t haystack_len = s21_strlen(haystack);
    s21_size_t needle_len = s21_strlen(needle);

    if (needle_len <= haystack_len) {
      s21_size_t i = 0;

      while (i <= haystack_len - needle_len) {
        s21_size_t j = 0;

        while (j < needle_len && haystack[i + j] == needle[j]) {
          j++;
        }

        if (j == needle_len) {
          res = (char *)(haystack + i);
          break;
        }

        i++;
      }
    }
  }

  return res;
}
