#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *new_str = NULL;
  void *result = NULL;
  if (str != NULL && src != NULL && start_index <= s21_strlen(src)) {
    new_str = (char *)malloc(s21_strlen(src) + s21_strlen(str) - 1);
    result = new_str;
    if (start_index) {
      s21_strncpy(new_str, src, start_index);
      s21_strcat(new_str, str);
      s21_strcat(new_str, src + start_index);
    } else {
      s21_strcpy(new_str, str);
      s21_strcat(new_str, src);
    }
  }
  return result;
}
