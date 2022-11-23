#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  const char *buf_src = (char *)src;
  char *buf_dest = (char *)dest;
  for (; n > 0; n--, buf_dest++, buf_src++) {
    (*buf_dest = *buf_src);
  }
  return dest;
}
