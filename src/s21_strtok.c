#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *str_const;
  if (str == NULL) {
    str = str_const;
  }
  char *part = str;
  if (delim != NULL) {
    if (str != NULL) {
      int exit_flag = 0;
      for (int i = 0; str[i] && exit_flag != 1; i++) {
        for (char *delim_buf = (char *)delim; *delim_buf != '\0'; delim_buf++) {
          if (str[i] == *delim_buf) {
            str[i] = '\0';
            break;
          }
        }
        if (str[i] == '\0' && i == 0) {
          str++;
          i--;
          part = str;
          continue;
        }
        if (str[i] == '\0') {
          str_const = &str[i + 1];
          exit_flag = 1;
        }
      }
      str_const = NULL;
      if (*part == '\0' && exit_flag != 1) {
        part = NULL;
      }
    }
  } else {
    str_const = str;
  }
  return part;
}
