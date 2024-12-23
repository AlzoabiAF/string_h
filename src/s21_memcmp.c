#include "s21_string.h"

#ifdef __linux__

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1 = (const unsigned char *)str1;
  const unsigned char *p2 = (const unsigned char *)str2;
  int result = 0;
  bool success = true;
  while (n-- && success) {
    if (*p1 != *p2) {
      result = (int)(*p1) - (int)(*p2);
      success = false;
    }
    p1++;
    p2++;
  }

  return result;
}

#elif defined(__APPLE__)

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1 = (const unsigned char *)str1;
  const unsigned char *p2 = (const unsigned char *)str2;
  int result = 0;

  for (s21_size_t i = 0; i < n && result == 0; i++) {
    result = (p1[i] > p2[i]) ? 1 : (p1[i] < p2[i]) ? -1 : 0;
  }

  return result;
}

#endif