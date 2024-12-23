#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;

  if (src) {
    if (!trim_chars) trim_chars = " ";

    s21_size_t start = 0;
    s21_size_t end = s21_strlen(src);

    while (start < end && s21_strchr(trim_chars, src[start])) {
      start++;
    }

    while (end > start && s21_strchr(trim_chars, src[end - 1])) {
      end--;
    }

    s21_size_t res_len = end - start;
    res = (char *)malloc((res_len + 1) * sizeof(char));

    if (res) {
      for (s21_size_t i = 0; i < res_len; i++) {
        res[i] = src[start + i];
      }
      res[res_len] = '\0';
    }
  }

  return res;
}
