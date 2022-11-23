#include "s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
  int flag = 0;
  int score = 0;

  for (int i = 0; str1[i] != '\0'; i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        flag++;
        break;
      }
    }
    score++;
    if (flag == 0 || score != flag) {
      break;
    }
  }
  return flag;
}
