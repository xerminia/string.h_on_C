#include "s21_error_list.h"
#include "s21_string.h"

char *s21_strerror(int errnum) {
  int d = 0;
#ifdef __APPLE__
  static const char *err_pointer[] = ERRLIST;
  d = 106;
#elif __linux__
  static const char *err_pointer[] = ERRLIST2;
  d = 133;
#endif
  const void *a;
  char *z;
  if (errnum >= 0 && errnum <= d) {
    a = err_pointer[errnum];
  } else {
    static char zero[100] = {"Unknown error: "};
    a = zero;
    char zero_code[25];
    int b = 0, score = -1;
    if (errnum < 0) {
      zero[15] = '-';
      zero[16] = '\0';
      errnum = -errnum;
    }
    while (errnum) {
      b = b * 10 + errnum % 10;
      errnum /= 10;
      score++;
    }
    zero_code[score + 1] = '\0';
    int i = 0;
    while (score != -1) {
      zero_code[i] = b % 10 + '0';
      b /= 10;
      i++;
      score--;
    }
    s21_strcat(zero, zero_code);
  }
  z = (char *)a;
  return z;
}
