#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *cln = dest;
  while (*dest != '\0') {
    dest++;
  }
  while (n) {
    *dest++ = *src++;
    *dest++ = '\0';
    n--;
  }
  return cln;
}
