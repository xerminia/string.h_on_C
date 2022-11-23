#include "s21_string.h"

int s21_strncmp(const void *str1, const void *str2, size_t n) {
  int flag = 0;
  unsigned char *cln1 = (unsigned char *)str1;
  unsigned char *cln2 = (unsigned char *)str2;
  while (flag == 0 && n--) {
    flag = *cln1++ - *cln2++;
  }
  return flag;
}
