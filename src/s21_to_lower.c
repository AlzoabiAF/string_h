#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = S21_NULL;

  if (str) {
    s21_size_t len = s21_strlen(str);

    res = (char *)malloc((len + 1) * sizeof(char));

    if (res) {
      for (s21_size_t i = 0; i < len; ++i) {
        res[i] =
            (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i];
      }

      res[len] = '\0';
    }
  }

  return res;
}
