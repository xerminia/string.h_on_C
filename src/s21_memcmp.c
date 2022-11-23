#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int flag = 0;
  char *cln1 = (char *)str1;
  char *cln2 = (char *)str2;

  while (flag == 0 && n--) {
    flag = *cln1++ - *cln2++;
  }
  return flag;
}
