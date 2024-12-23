#include "s21_strerror.h"

char *s21_strerror(int errnum) {
  static const char *errors_arr[SIZE_OF_ERRORLIST] = ERRORLIST;
  static char result_error[1024];
  char *res = S21_NULL;

  if (errnum >= 0 && errnum < SIZE_OF_ERRORLIST) {
    res = (char *)errors_arr[errnum];
  } else {
    s21_strcpy(result_error, UNKNOWN);
    s21_itoa(errnum, result_error + s21_strlen(UNKNOWN));
    res = result_error;
  }

  return res;
}

void s21_itoa(int num, char *str) {
  int is_negative = 0;
  s21_size_t i = 0;

  if (num < 0) {
    is_negative = 1;
    num = -num;
  }

  do {
    str[i++] = (num % 10) + '0';
    num /= 10;
  } while (num > 0);

  if (is_negative) {
    str[i++] = '-';
  }

  str[i] = '\0';
  s21_reverse_str(str, i);
}

void s21_reverse_str(char *str, s21_size_t len) {
  s21_size_t start = 0, end = len - 1;

  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    start++;
    end--;
  }
}
