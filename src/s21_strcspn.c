#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t aboba = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      break;
    } else {
      str1++;
      aboba++;
    }
  }
  return aboba;
}
