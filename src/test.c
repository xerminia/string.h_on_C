#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_memchrTest) {
  char *buf, *buf2;
  buf = s21_memchr("1234567890", 53, 7);
  buf2 = memchr("1234567890", 53, 7);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memchr("qwer5tyuiop", 53, 10);
  buf2 = memchr("qwer5tyuiop", 53, 10);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memchr("qwerty123456", 53, 11);
  buf2 = memchr("qwerty123456", 53, 11);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_memcmpTest) {
  int d, d2;
  char str1[100] = "111qwe", str2[100] = "23eq";
  char str3[100] = "q123edwq13", str4[100] = "wqe21";
  d = s21_memcmp(str1, str2, 5);
  d2 = memcmp(str1, str2, 5);
  ck_assert_int_eq(d, d2);
  d = s21_memcmp(str3, str4, 4);
  d2 = memcmp(str3, str4, 4);
  ck_assert_int_eq(d, d2);
  d = s21_memcmp(str3, str4, 0);
  d2 = memcmp(str3, str4, 0);
  ck_assert_int_eq(d, d2);
  d = s21_memcmp(str3, str4, 12);
  d2 = memcmp(str3, str4, 12);
  ck_assert_int_eq(d, d2);
}
END_TEST

START_TEST(s21_memcpyTest) {
  char str1[100] = "qwerty123456", str2[100] = "123456qwerty";
  char str3[100] = "", str4[100] = "1234567890";
  char *buf, *buf2;
  buf = s21_memcpy(str1, str2, 3);
  buf2 = memcpy(str1, str2, 3);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memcpy(str1, str2, 12);
  buf2 = memcpy(str1, str2, 12);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memcpy(str3, str4, 50);
  buf2 = memcpy(str3, str4, 50);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memcpy(str4, str3, 5);
  buf2 = memcpy(str4, str3, 5);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_memmoveTest) {
  char str1[100] = "qwerty123", str2[100] = "123456qwerty";
  char str3[100] = "", str4[100] = "1234567890";
  char *buf, *buf2;
  buf = s21_memmove(str1, str2, 3);
  buf2 = memmove(str1, str2, 3);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memmove(str2, str1, 12);
  buf2 = memmove(str2, str1, 12);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memmove(str3, str4, 50);
  buf2 = memmove(str3, str4, 50);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memmove(str4, str3, 5);
  buf2 = memmove(str4, str3, 5);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_memsetTest) {
  char str1[256] = "12345";
  char *buf, *buf2;
  buf = s21_memset(str1, 53, 4);
  buf2 = memset(str1, 53, 4);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memset(str1, 53, 1);
  buf2 = memset(str1, 53, 1);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memset(str1, 240, 4);
  buf2 = memset(str1, 240, 4);
  ck_assert_str_eq(buf, buf2);
  buf = s21_memset(str1, 53, 5);
  buf2 = memset(str1, 53, 5);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strcatTest) {
  char str1[100] = "qwerty123", str2[100] = "123456qwerty";
  char str3[100] = "", str4[100] = "1234567890";
  char *buf, *buf2;
  buf = s21_strcat(str1, str2);
  buf2 = strcat(str1, str2);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strcat(str2, str1);
  buf2 = strcat(str2, str1);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strcat(str3, str4);
  buf2 = strcat(str3, str4);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strcat(str4, str3);
  buf2 = strcat(str4, str3);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strncatTest) {
  char str1[100] = "qwerty123", str2[100] = "123456qwerty";
  char str3[100] = "", str4[100] = "1234567890";
  char *buf, *buf2;
  buf = s21_strncat(str1, str2, 10);
  buf2 = strncat(str1, str2, 10);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strncat(str2, str1, 10);
  buf2 = strncat(str2, str1, 10);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strncat(str3, str4, 10);
  buf2 = strncat(str3, str4, 10);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strncat(str4, str3, 0);
  buf2 = strncat(str4, str3, 0);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strchrTest) {
  char *buf, *buf2;
  buf = s21_strchr("12312315232", 53);
  buf2 = strchr("12312315232", 53);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strchr("5qwwwwweeeee", 53);
  buf2 = strchr("5qwwwwweeeee", 53);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strchr("eewweewwqqww5", 53);
  buf2 = strchr("eewweewwqqww5", 53);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strchr("5eewweewwqqww5", 53);
  buf2 = strchr("5eewweewwqqww5", 53);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strcmpTest) {
  char str1[100] = "1234", str2[100] = "4321";
  char str3[100] = "1234567890", str4[100] = "qwertyuiop";
  char str5[100] = "1234567890";
  int d, d2;
  d = s21_strcmp(str1, str2);
  d2 = strcmp(str1, str2);
  ck_assert_int_eq(d, d2);
  d = s21_strcmp(str2, str1);
  d2 = strcmp(str2, str1);
  ck_assert_int_eq(d, d2);
  d = s21_strcmp(str3, str4);
  d2 = strcmp(str3, str4);
  ck_assert_int_eq(d, d2);
  d = s21_strcmp(str5, str3);
  d2 = strcmp(str5, str3);
  ck_assert_int_eq(d, d2);
}
END_TEST

START_TEST(s21_strncmpTest) {
  char str1[100] = "1234", str2[100] = "4321";
  char str3[100] = "1234567890", str4[100] = "qwertyuiop";
  char str5[100] = "1234567890";
  int d, d2;
  d = s21_strncmp(str1, str2, 4);
  d2 = strncmp(str1, str2, 4);
  ck_assert_int_eq(d, d2);
  d = s21_strncmp(str3, str4, 10);
  d2 = strncmp(str3, str4, 10);
  ck_assert_int_eq(d, d2);
  d = s21_strncmp(str3, str5, 10);
  d2 = strncmp(str3, str5, 10);
  ck_assert_int_eq(d, d2);
  d = s21_strncmp(str3, str5, 5);
  d2 = strncmp(str3, str5, 5);
  ck_assert_int_eq(d, d2);
}
END_TEST

START_TEST(s21_strcpyTest) {
  char str1[100] = "qwerty123", str2[100] = "123456qwerty";
  char str3[100] = "", str4[100] = "1234567890";
  char *buf, *buf2;
  buf = s21_strcpy(str1, str2);
  buf2 = strcpy(str1, str2);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strcpy(str2, str1);
  buf2 = strcpy(str2, str1);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strcpy(str3, str4);
  buf2 = strcpy(str3, str4);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strcpy(str4, str3);
  buf2 = strcpy(str4, str3);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strncpyTest) {
  char str1[100] = "qwerty123", str2[100] = "123456qwerty";
  char str3[100] = "", str4[100] = "1234567890";
  char *buf, *buf2;
  buf = s21_strncpy(str1, str2, 10);
  buf2 = strncpy(str1, str2, 10);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strncpy(str2, str1, 10);
  buf2 = strncpy(str2, str1, 10);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strncpy(str3, str4, 10);
  buf2 = strncpy(str3, str4, 10);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strncpy(str4, str3, 0);
  buf2 = strncpy(str4, str3, 0);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strcspnTest) {
  size_t d, d2;
  d = s21_strcspn("123", "321");
  d2 = strcspn("123", "321");
  ck_assert_int_eq(d, d2);
  d = s21_strcspn("123qwe", "qwe");
  d2 = strcspn("123qwe", "qwe");
  ck_assert_int_eq(d, d2);
  d = s21_strcspn("123", "qw3");
  d2 = strcspn("123", "qw3");
  ck_assert_int_eq(d, d2);
  d = s21_strcspn("qwe123", "123");
  d2 = strcspn("qwe123", "123");
  ck_assert_int_eq(d, d2);
}
END_TEST

START_TEST(s21_strerrorTest) {
  static char buf[256], buf2[256];
  int num = -99;
  s21_strcat(buf, s21_strerror(num));
  s21_strcat(buf2, strerror(num));
  ck_assert_str_eq(buf, buf2);
  static char buf3[256], buf4[256];
  num = 25;
  s21_strcat(buf3, s21_strerror(num));
  s21_strcat(buf4, strerror(num));
  ck_assert_str_eq(buf3, buf4);
  static char buf5[256], buf6[256];
  num = 106;
  s21_strcat(buf5, s21_strerror(num));
  s21_strcat(buf6, strerror(num));
  ck_assert_str_eq(buf5, buf6);
}
END_TEST

START_TEST(s21_strlenTest) {
  int d, d2;
  d = s21_strlen("12345");
  d2 = strlen("12345");
  ck_assert_int_eq(d, d2);
  d = s21_strlen("12345qwe");
  d2 = strlen("12345qwe");
  ck_assert_int_eq(d, d2);
  d = s21_strlen("1234567890");
  d2 = strlen("1234567890");
  ck_assert_int_eq(d, d2);
  d = s21_strlen("12345111111");
  d2 = strlen("12345111111");
  ck_assert_int_eq(d, d2);
}
END_TEST

START_TEST(s21_strpbrkTest) {
  char *buf, *buf2;
  buf = s21_strpbrk("qwe1235qwe", "5");
  buf2 = strpbrk("qwe1235qwe", "5");
  ck_assert_str_eq(buf, buf2);
  buf = s21_strpbrk("123qwe5123qwe", "tx5");
  buf2 = strpbrk("123qwe5123qwe", "tx5");
  ck_assert_str_eq(buf, buf2);
  buf = s21_strpbrk("123qwe5123qwe", "nb2v");
  buf2 = strpbrk("123qwe5123qwe", "nb2v");
  ck_assert_str_eq(buf, buf2);
  buf = s21_strpbrk("123qwe5123qwe", "22");
  buf2 = strpbrk("123qwe5123qwe", "22");
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strrchrTest) {
  char *buf, *buf2;
  buf = s21_strrchr("12312315232", 53);
  buf2 = strrchr("12312315232", 53);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strrchr("5qwwwwweeeee", 53);
  buf2 = strrchr("5qwwwwweeeee", 53);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strrchr("eewweewwqqww5", 53);
  buf2 = strrchr("eewweewwqqww5", 53);
  ck_assert_str_eq(buf, buf2);
  buf = s21_strrchr("5eewweewwqqww5", 0);
  buf2 = strrchr("5eewweewwqqww5", 0);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strspnTest) {
  int d, d2;
  d = s21_strspn("123", "321");
  d2 = strspn("123", "321");
  ck_assert_int_eq(d, d2);
  d = s21_strspn("123qwe", "qwe");
  d2 = strspn("123qwe", "qwe");
  ck_assert_int_eq(d, d2);
  d = s21_strspn("123", "qw3");
  d2 = strspn("123", "qw3");
  ck_assert_int_eq(d, d2);
  d = s21_strspn("123", "qw3");
  d2 = strspn("123", "qw3");
  ck_assert_int_eq(d, d2);
}
END_TEST

START_TEST(s21_strstrTest) {
  char *buf, *buf2;
  buf = s21_strstr("qwe123qwe", "123");
  buf2 = strstr("qwe123qwe", "123");
  ck_assert_str_eq(buf, buf2);
  buf = s21_strstr("123qwe123", "qwe");
  buf2 = strstr("123qwe123", "qwe");
  ck_assert_str_eq(buf, buf2);
  buf = s21_strstr("qwe123", "qwe");
  buf2 = strstr("qwe123", "qwe");
  ck_assert_str_eq(buf, buf2);
  buf = s21_strstr("qwe123", "qwe");
  buf2 = strstr("qwe123", "qwe");
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(s21_strtokTest) {
  char str1[100] = "123qwe123qwe123qwe", str2[100] = "eeeeeeeeee2eeee";
  char str3[100] = "qwe,qwe-qwe=qwe;", str4[100] = "w4980eghjps39123vzlk";
  char *buf, *buf2;
  buf = s21_strtok(str1, "eqw");
  buf2 = strtok(str1, "eqw");
  while (buf != NULL && buf2 != NULL) {
    ck_assert_str_eq(buf, buf2);
    buf = s21_strtok(NULL, "eqw");
    buf2 = strtok(NULL, "eqw");
  }
  buf = s21_strtok(str2, "e");
  buf2 = strtok(str2, "e");
  while (buf != NULL && buf2 != NULL) {
    ck_assert_str_eq(buf, buf2);
    buf = s21_strtok(NULL, "eqw");
    buf2 = strtok(NULL, "eqw");
  }
  buf = s21_strtok(str3, ",-=");
  buf2 = strtok(str3, ",-=");
  while (buf != NULL && buf2 != NULL) {
    ck_assert_str_eq(buf, buf2);
    buf = s21_strtok(NULL, "eqw");
    buf2 = strtok(NULL, "eqw");
  }
  buf = s21_strtok(str4, "1 2");
  buf2 = strtok(str4, "1 2");
  while (buf != NULL && buf2 != NULL) {
    ck_assert_str_eq(buf, buf2);
    buf = s21_strtok(NULL, "eqw");
    buf2 = strtok(NULL, "eqw");
  }
}
END_TEST

START_TEST(spec_c) {
  char buf[256], buf2[256];
  char a = '1', b = '=';
  s21_sprintf(buf, "%-5c%2c%c%10c%*c", a, a, b, a, 5, a);
  sprintf(buf2, "%-5c%2c%c%10c%*c", a, a, b, a, 5, a);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_d_and_i) {
  char buf[256], buf2[256];
  int a = 0, c = 1, d = 100, e = -100;
  long int z = 2523416;
  short int q = 1;
  s21_sprintf(buf, "% d%-10.9d%+9.10d%10.5d%10.0d%10.i%-10.5ld%+5.10hd", d, a,
              e, c, d, e, z, q);
  sprintf(buf2, "% d%-10.9d%+9.10d%10.5d%10.0d%10.i%-10.5ld%+5.10hd", d, a, e,
          c, d, e, z, q);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_e) {
  char buf[256], buf2[256];
  double a = -349.744445340;
  s21_sprintf(buf, "% e%+.4e%-10e%#9.10e%05e", a, a, a, a, a);
  sprintf(buf2, "% e%+.4e%-10e%#9.10e%05e", a, a, a, a, a);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_E) {
  char buf[256], buf2[256];
  double a = 0.0000000000004444;
  double b = 1.2345;
  s21_sprintf(buf, "% E%-13.6E%+4E%012.16E%+4.5E", a, a, b, a, b);
  sprintf(buf2, "% E%-13.6E%+4E%012.16E%+4.5E", a, a, b, a, b);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_f) {
  char buf[256], buf2[256];
  float a = 0.00156, b = 0.25, c = -125.8;
  s21_sprintf(buf, "%f%-13.6f%+4f%012.16f%+4.5f", a, b, c, a, b);
  sprintf(buf2, "%f%-13.6f%+4f%012.16f%+4.5f", a, b, c, a, b);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_g_and_G) {
  char buf[256], buf2[256];
  double a = 0.00156, b = 1.25;
  s21_sprintf(buf, "%10.5g%G%10g%10G", a, b, a, b);
  sprintf(buf2, "%10.5g%G%10g%10G", a, b, a, b);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_o) {
  char buf[256], buf2[256];
  unsigned int a = 25, b = 0, c = 239, d = 5555;
  unsigned long int z = 2523416;
  unsigned short int q = 1;
  s21_sprintf(buf, "%-5.2o%#1.0o%10.15o%5.5o%ho%lo", a, b, c, d, q, z);
  sprintf(buf2, "%-5.2o%#1.0o%10.15o%5.5o%ho%lo", a, b, c, d, q, z);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_s) {
  char buf[256], buf2[256];
  char a[100] = {"ABOBA BOBA BOB BO O"};
  s21_sprintf(buf, "!!%-10.0s%10.5s%5.10s%25s!!", a, a, a, a);
  sprintf(buf2, "!!%-10.0s%10.5s%5.10s%25s!!", a, a, a, a);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_u) {
  char buf[256], buf2[256];
  unsigned int a = 487456;
  unsigned long int z = 2523416;
  unsigned short int q = 1;
  s21_sprintf(buf, "%u%-13u%-u%25u%*.9u%hu%lu", a, a, a, a, 6, a, q, z);
  sprintf(buf2, "%u%-13u%-u%25u%*.9u%hu%lu", a, a, a, a, 6, a, q, z);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_x) {
  char buf[256], buf2[256];
  int a = 3454;
  unsigned long int z = 0xF4AFF;
  unsigned short int q = 12;
  s21_sprintf(buf, "%-7x%#5.8x%-9.2x%#*x%x%hx%lx", a, a, a, 14, a, a, q, z);
  sprintf(buf2, "%-7x%#5.8x%-9.2x%#*x%x%hx%lx", a, a, a, 14, a, a, q, z);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_X) {
  char buf[256], buf2[256];
  int a = 564567;
  unsigned long int z = 0xF4AFF;
  unsigned short int q = 12;
  s21_sprintf(buf, "%X%3.2X%-4.1X%#17X%*.4X%hX%lX", a, a, a, a, 5, a, q, z);
  sprintf(buf2, "%X%3.2X%-4.1X%#17X%*.4X%hX%lX", a, a, a, a, 5, a, q, z);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_p) {
  char buf[256], buf2[256];
  int *a = NULL;
  s21_sprintf(buf, "%*p%-4p%p%6p%-*p", 3, &a, &a, &a, &a, 8, &a);
  sprintf(buf2, "%*p%-4p%p%6p%-*p", 3, &a, &a, &a, &a, 8, &a);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(spec_n) {
  char buf[256], buf2[256];
  int a, b;
  s21_sprintf(buf, "KEKA %%%%KEKA %n", &a);
  sprintf(buf2, "KEKA %%%%KEKA %n", &b);
  ck_assert_str_eq(buf, buf2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(spec_c_s_d_f) {
  char buf[256], buf2[256];
  char a = '1', b[50] = "ABOBA";
  int c = -15;
  float d = 14.5;
  s21_sprintf(buf, "%10c%20s%+10.5d%-5.*f", a, b, c, 2, d);
  sprintf(buf2, "%10c%20s%+10.5d%-5.*f", a, b, c, 2, d);
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(to_lower) {
  char b[50] = "ABOBA";
  char *buf = s21_to_lower(b);
  ck_assert_str_eq(buf, "aboba");
  free(buf);
  char c[50] = "QWERTY";
  char *buf2 = s21_to_lower(c);
  ck_assert_str_eq(buf2, "qwerty");
  free(buf2);
  char d[50] = "QwErTy";
  char *buf3 = s21_to_lower(d);
  ck_assert_str_eq(buf3, "qwerty");
  free(buf3);
}
END_TEST

START_TEST(trim) {
  char b[50] = "ABOBA", c[10] = "AB";
  char *buf = s21_trim(b, c);
  ck_assert_str_eq(buf, "O");
  free(buf);
  char d[50] = "QWERTY", e[10] = "QWY";
  char *buf2 = s21_trim(d, e);
  ck_assert_str_eq(buf2, "ERT");
  free(buf2);
}
END_TEST

START_TEST(to_upper) {
  char b[50] = "aboba";
  char *buf = s21_to_upper(b);
  ck_assert_str_eq(buf, "ABOBA");
  free(buf);
  char d[50] = "qWeRTy";
  char *buf2 = s21_to_upper(d);
  ck_assert_str_eq(buf2, "QWERTY");
  free(buf2);
}
END_TEST

START_TEST(insert) {
  char b[50] = "aboba", c[50] = "ABOBA";
  size_t i = 3;
  char *buf2 = s21_insert(b, c, i);
  ck_assert_str_eq(buf2, "aboABOBAba");
  free(buf2);
  i = 0;
  char *buf = s21_insert(b, c, i);
  ck_assert_str_eq(buf, "ABOBAaboba");
  free(buf);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_memchrTest);
  tcase_add_test(tc1_1, s21_memcmpTest);
  tcase_add_test(tc1_1, s21_memcpyTest);
  tcase_add_test(tc1_1, s21_memmoveTest);
  tcase_add_test(tc1_1, s21_memsetTest);
  tcase_add_test(tc1_1, s21_strcatTest);
  tcase_add_test(tc1_1, s21_strncatTest);
  tcase_add_test(tc1_1, s21_strchrTest);
  tcase_add_test(tc1_1, s21_strcmpTest);
  tcase_add_test(tc1_1, s21_strncmpTest);
  tcase_add_test(tc1_1, s21_strcpyTest);
  tcase_add_test(tc1_1, s21_strncpyTest);
  tcase_add_test(tc1_1, s21_strcspnTest);
  tcase_add_test(tc1_1, s21_strerrorTest);
  tcase_add_test(tc1_1, s21_strlenTest);
  tcase_add_test(tc1_1, s21_strpbrkTest);
  tcase_add_test(tc1_1, s21_strrchrTest);
  tcase_add_test(tc1_1, s21_strspnTest);
  tcase_add_test(tc1_1, s21_strstrTest);
  tcase_add_test(tc1_1, s21_strtokTest);
  tcase_add_test(tc1_1, spec_c);
  tcase_add_test(tc1_1, spec_d_and_i);
  tcase_add_test(tc1_1, spec_e);
  tcase_add_test(tc1_1, spec_E);
  tcase_add_test(tc1_1, spec_f);
  tcase_add_test(tc1_1, spec_g_and_G);
  tcase_add_test(tc1_1, spec_o);
  tcase_add_test(tc1_1, spec_s);
  tcase_add_test(tc1_1, spec_u);
  tcase_add_test(tc1_1, spec_x);
  tcase_add_test(tc1_1, spec_X);
  tcase_add_test(tc1_1, spec_p);
  tcase_add_test(tc1_1, spec_n);
  tcase_add_test(tc1_1, spec_c_s_d_f);
  tcase_add_test(tc1_1, to_lower);
  tcase_add_test(tc1_1, trim);
  tcase_add_test(tc1_1, to_upper);
  tcase_add_test(tc1_1, insert);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
