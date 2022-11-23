#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = NULL;
  if (c == 0) {
    result = ((char *)str + s21_strlen(str));
  } else {
    while (*str) {
      if (*str == c) {
        result = (char *)str;
        break;
      }
      ++str;
    }
  }
  return result;
}
