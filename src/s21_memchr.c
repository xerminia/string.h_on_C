#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  char *arr = NULL;
  char *cln = (char *)str;
  for (size_t i = 0; i < n && arr == NULL; i++) {
    if (cln[i] == c) {
      arr = &cln[i];
    }
  }
  return arr;
}
