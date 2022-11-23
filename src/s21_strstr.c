#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *t = NULL;
  char *hay = (char *)haystack;
  char *nee = (char *)needle;
  for (int i = 0; hay[i] != '\0'; i++) {
    int x = i;
    int y = i;
    for (int j = 0; nee[j] == hay[x] && nee[j] != '\0'; j++, x++) {
      if (nee[j + 1] == '\0') {
        t = &hay[y];
      }
    }
  }
  if (s21_strlen(nee) == 0) {
    t = &hay[0];
  }
  return t;
}
