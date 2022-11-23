#include "s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
  char unsigned *cln = str;
  for (size_t i = 0; i < n; i++) {
    cln[i] = (unsigned char)c;
  }
  return str;
}
