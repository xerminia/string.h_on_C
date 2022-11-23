#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *t = NULL;
  char *cln1 = (char *)str1;
  char *cln2 = (char *)str2;
  for (int i = 0; cln1[i] != '\0' && t == NULL; i++) {
    for (int j = 0; cln2[j] != '\0' && t == NULL; j++) {
      if (cln1[i] == cln2[j]) {
        t = &cln1[i];
      }
    }
  }
  return t;
}
