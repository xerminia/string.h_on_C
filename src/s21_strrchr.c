#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = NULL;
  if (c == 0) {
    result = ((char *)str + s21_strlen(str));
  } else {
    while (*str) {
      if (*str == c) {
        result = (char *)str;
      }
      ++str;
    }
  }
  return result;
}
