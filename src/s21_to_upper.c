#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *res = S21_NULL;

  if (str) {
    s21_size_t len = s21_strlen(str);
    res = (char *)malloc((len + 1) * sizeof(char));

    if (res) {
      for (s21_size_t i = 0; i < len; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          res[i] = str[i] - ('a' - 'A');
        } else if ((unsigned char)str[i] >= 0xE0) {
          res[i] = str[i] - 0x20;
        } else {
          res[i] = str[i];
        }
      }

      res[len] = '\0';
    }
  }

  return res;
}
