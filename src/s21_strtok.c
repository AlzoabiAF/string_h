#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *current;
  char *token_start = S21_NULL;

  if (delim != S21_NULL && (str != S21_NULL || current != S21_NULL)) {
    if (str != S21_NULL) {
      current = str;
    }

    while (*current != '\0' && s21_strchr(delim, *current)) {
      current++;
    }

    if (*current != '\0') {
      token_start = current;
      while (*current != '\0' && !s21_strchr(delim, *current)) {
        current++;
      }

      if (*current != '\0') {
        *current = '\0';
        current++;
      } else {
        current = S21_NULL;
      }
    }
  }

  return token_start;
}
