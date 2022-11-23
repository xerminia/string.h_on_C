#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *new_str = NULL;
  void *result = NULL;
  if (str != NULL) {
    char *cln_str = (char *)str;
    new_str = (char *)malloc((s21_strlen(cln_str) + 1) * sizeof(char));
    result = new_str;
    if (new_str != NULL) {
      int d = -1;
      for (int i = 0; cln_str[i] != '\0'; i++) {
        new_str[i] = cln_str[i];
        if ((new_str[i] >= 'a') && (new_str[i] <= 'z')) {
          new_str[i] = new_str[i] - ('a' - 'A');
        }
        d = i;
      }
      new_str[d + 1] = '\0';
    }
  }
  return result;
}
