#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, size_t n) {
  char *buf_dest = (char *)dest;
  const char *buf_src;
  buf_src = src;
  if (buf_dest < buf_src) {
    s21_memcpy(dest, src, n);
  } else if (buf_dest > buf_src) {
    buf_dest += n - 1;
    buf_src += n - 1;
    for (; n > 0; n--, buf_dest--, buf_src--) (*buf_dest = *buf_src);
  }
  return dest;
}
