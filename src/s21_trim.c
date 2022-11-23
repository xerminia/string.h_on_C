#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_src = (char *)src;
  if (src && trim_chars) {
    char *cln_src = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    while (*cln_src && s21_strchr(trim_chars, *cln_src)) {
      cln_src++;
    }
    while (end_str != cln_src && s21_strchr(trim_chars, *(end_str - 1))) {
      end_str--;
    }
    new_src = (char *)malloc((end_str - cln_src + 1) * sizeof(char));
    if (new_src) {
      s21_strncpy(new_src, cln_src, end_str - cln_src);
      *(new_src + (end_str - cln_src)) = '\0';
    }
  }
  return new_src;
}
