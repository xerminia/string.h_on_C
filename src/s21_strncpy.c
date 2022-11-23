#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *cln = dest;
  while (n) {
    *dest++ = *src++;
    n--;
  }
  *dest++ = '\0';
  return cln;
}
