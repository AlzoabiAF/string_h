#include <math.h>

#include "s21_string.h"

int ISnumber(char str) { return (str >= '0' && str <= '9') ? 1 : 0; }

char *IntToString(int substr, bool minus, int width) {
  s21_size_t buffer_size = 50, pos = 0;
  ;
  char *res = (char *)malloc(buffer_size);
  char temp[buffer_size];

  bool is_negative = substr < 0;

  if (is_negative) substr = -substr;

  do {
    temp[pos++] = (char)((substr % 10) + '0');
    substr /= 10;
  } while (substr > 0);

  if (is_negative) temp[pos++] = '-';

  for (s21_size_t i = 0; i < pos / 2; ++i) {
    char tmp = temp[i];
    temp[i] = temp[pos - i - 1];
    temp[pos - i - 1] = tmp;
  }

  temp[pos] = '\0';

  s21_size_t len = pos,
             padding = (s21_size_t)width > len ? (s21_size_t)width - len : 0;

  if (minus) {
    s21_strcpy(res, temp);
    for (s21_size_t i = len; i < len + padding; ++i) res[i] = ' ';
    res[len + padding] = '\0';
  } else {
    for (s21_size_t i = 0; i < padding; ++i) res[i] = ' ';
    s21_strcpy(res + padding, temp);
  }

  return res;
}

char *DoubleToString(double n, int precision, bool plus, int width,
                     bool minus) {
  if (precision < 0) precision = 6;

  s21_size_t buffer_size = 100;
  char *buffer = (char *)malloc(buffer_size);

  double factor = pow(10, precision), rounded_n = round(n * factor) / factor;
  int integer_part = (int)rounded_n;
  long fractional_part = round(fabs(rounded_n - integer_part) * factor);

  char *int_str = IntToString(integer_part, false, 0);
  char frac_str[buffer_size];
  snprintf(frac_str, buffer_size, ".%0*ld", precision, fractional_part);
  snprintf(buffer, buffer_size, "%s%s", int_str, frac_str);

  free(int_str);

  if (plus && n >= 0) plus = false;

  s21_size_t buffer_len = s21_strlen(buffer);
  if ((s21_size_t)width > buffer_len) {
    char *temp = (char *)malloc(width + 1);
    s21_size_t padding = width - buffer_len;

    if (minus || plus) {
      padding = -2;
    }

    for (s21_size_t i = 0; i < padding; ++i) {
      temp[i] = ' ';
    }

    s21_strcpy(temp + padding, buffer);
    free(buffer);
    buffer = temp;
  }

  return buffer;
}

char *chooseSymbol(va_list *factor, char specialSymbol, int precision,
                   bool minus, bool plus, int width, bool Short, bool Long) {
  char *res = S21_NULL;
  switch (specialSymbol) {
    case 'c': {
      res = (char *)malloc(2);
      if (res) {
        res[0] = (char)va_arg(*factor, int);
        res[1] = '\0';
      }
      break;
    }
    case 'd':
    case 'i': {
      if (Short) {
        res = IntToString((short int)va_arg(*factor, int), minus, width);
      } else if (Long) {
        res = IntToString(va_arg(*factor, long int), minus, width);
      } else {
        res = IntToString(va_arg(*factor, int), minus, width);
      }
      break;
    }
    case 'f': {
      ;
      res = DoubleToString(va_arg(*factor, double), precision, plus, width,
                           minus);
      break;
    }
    case 's': {
      char *str = va_arg(*factor, char *);
      res = (char *)malloc(s21_strlen(str) + 1);
      if (res) s21_strcpy(res, str);
      break;
    }
    case 'u': {
      res = IntToString((int)va_arg(*factor, unsigned int), minus, width);
      break;
    }
    case '%': {
      res = (char *)malloc(2);
      if (res) {
        res[0] = '%';
        res[1] = '\0';
      }
      break;
    }
  }
  return res;
}

void addSpaceIfNice(char **chosenSymbol, int space) {
  char *orig = (char *)malloc(s21_strlen(*chosenSymbol) + 2);

  if (space && orig) {
    orig[0] = ' ';
    s21_strcpy(orig + 1, *chosenSymbol);
    free(*chosenSymbol);
    *chosenSymbol = orig;
  }
}

void processingSubstring(const char *specialSymbolWidth, char **substr,
                         int *space, bool *plus, bool *minus) {
  if (s21_strchr(specialSymbolWidth, **substr)) {
    switch (**substr) {
      case ' ':
        *space = 1;
        break;
      case '+':
        *plus = true;
        break;
      case '-':
        *minus = true;
        break;
    }
    (*substr)++;
  }
}

void parseNumberOptions(char **substr, int *width, int *pointnumber,
                        bool *Short, bool *Long) {
  while (ISnumber(**substr)) {
    *width = *width * 10 + (**substr - '0');
    (*substr)++;
  }

  if (**substr == '.') {
    (*substr)++;
    *pointnumber = 0;
    while (ISnumber(**substr)) {
      *pointnumber = *pointnumber * 10 + (**substr - '0');
      (*substr)++;
    }
  }

  if (**substr == 'h') {
    *Short = true;
    (*substr)++;
  }

  if (**substr == 'l') {
    *Long = true;
    (*substr)++;
  }
}

void addPlusAndTrimSpaceIfNice(char **chosenSymbol, char format, bool plus) {
  if (!(plus && (format == 'd' || format == 'f'))) return;

  if (chosenSymbol && *chosenSymbol) {
    s21_size_t len = s21_strlen(*chosenSymbol);
    char *orig = (char *)malloc(len + 2);  // +1 для плюса, +1 для \0
    if (orig) {
      s21_size_t index = 0, orig_index = 0;

      while ((*chosenSymbol)[index] == ' ') {
        orig[orig_index++] = (*chosenSymbol)[index++];
      }

      if ((*chosenSymbol)[index] != '-' && (*chosenSymbol)[index] != '+') {
        orig[orig_index++] = '+';
      }

      s21_strcpy(orig + orig_index, *chosenSymbol + index);

      if (orig[0] == ' ') {
        char *suborig = (char *)malloc(len + 1);  // +1 для \0
        if (suborig) {
          s21_size_t i;
          for (i = 1; orig[i] != '\0'; ++i) {
            suborig[i - 1] = orig[i];
          }
          suborig[i - 1] = '\0';
          free(orig);
          orig = suborig;
        }
      }

      free(*chosenSymbol);
      *chosenSymbol = orig;
    }
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  const char *specialSymbolType = "cdifsu%", *specialSymbolWidth = "-+ ";
  va_list factor;
  va_start(factor, format);
  char *format_copy = (char *)malloc((s21_strlen(format) + 1) * sizeof(char));
  for (s21_size_t i = 0; i <= s21_strlen(format); i++) {
    format_copy[i] = format[i];
  }
  char *substr = format_copy, *percent_pos;
  while ((percent_pos = s21_strchr(substr, '%')) != S21_NULL) {
    *percent_pos = '\0';
    s21_strcat(str, substr);
    substr = percent_pos + 1;
    int space = 0, width = 0, pointnumber = 6;
    bool plus = false, minus = false, Short = false, Long = false;
    processingSubstring(specialSymbolWidth, &substr, &space, &plus, &minus);
    parseNumberOptions(&substr, &width, &pointnumber, &Short, &Long);

    if (s21_strchr(specialSymbolType, *substr)) {
      char *chosenSymbol = chooseSymbol(&factor, *substr, pointnumber, minus,
                                        plus, width, Short, Long);
      if (chosenSymbol) {
        addSpaceIfNice(&chosenSymbol, space);
        addPlusAndTrimSpaceIfNice(&chosenSymbol, *substr, plus);

        s21_strcat(str, chosenSymbol);
        free(chosenSymbol);
      }
      substr++;
    }
  }

  s21_strcat(str, substr);
  va_end(factor);
  free(format_copy);

  return s21_strlen(str);
}