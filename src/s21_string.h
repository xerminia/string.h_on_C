#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#define S21_NULL 0

typedef unsigned int s21_size_t;

typedef struct {
  int flag, width, perc, len, spec, score;
} token;

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memmove(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const void *str1, const void *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *buf, ...);
void *parser_format(const char *f);
int str_num(const char *str1, const char *str2);
int parser_numbers(const char *f);
int parser_flag(const char *f);
int parser_lenght(const char *f);
int parser_specificator(const char *f);
void s21_chtoa(char sym, char *buf, int spec, int flag, int width, int perc);
void s21_itoa(long long num, char *buf, int width, int flag, int spec,
              int perc);
void s21_etoa(long double num, int perc, int spec, char *buf, int flag);
void s21_dtoa(long double num, int perc, char *buf, int flag, int spec);
void s21_utoa(unsigned long long num, char *buf, int width, int flag, int spec,
              int perc);
void *s21_ctoa(char *str, char *buf, int spec, int flag, int width, int perc);
void s21_uutoa(unsigned long long num, char *buf, int spec, int flag, int width,
               int perc);
char *fill(int score, int width, char *buf, int flag, int perc, int spec);
char *minus_or(int min, char *buf, int flag, int spec);
char *record(int score, long long num, char *buf, int perc);
void *flags_e(char *buf, int width, int flag, int score, char *temp_buff_diff,
              int perc, int spec);
char *record_p(int c, char *temp_mass, char *buf, int perc);

void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);

#endif  // SRC_S21_STRING_H_
