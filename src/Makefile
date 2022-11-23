CC = gcc
CFLAGS = -Wall -Werror -Wall
FLAG = --coverage
LCOV = -I../../.brew/include -L../../.brew/Cellar/check/0.15.2/lib
CFILE = test.c s21_sprintf.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_strcat.c \
		s21_strchr.c s21_strcmp.c s21_strcpy.c s21_strcspn.c s21_strerror.c s21_strlen.c s21_strncat.c s21_strncmp.c \
		s21_strncpy.c s21_strpbrk.c s21_strrchr.c s21_strspn.c s21_strstr.c s21_strtok.c s21_to_lower.c \
		s21_trim.c s21_to_upper.c s21_insert.c
OFILE = s21_sprintf.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memmove.o s21_memset.o s21_strcat.o s21_strchr.o \
		s21_strcmp.o s21_strcpy.o s21_strcspn.o s21_strerror.o s21_strlen.o s21_strncat.o s21_strncmp.o \
		s21_strncpy.o s21_strpbrk.o s21_strrchr.o s21_strspn.o s21_strstr.o s21_strtok.o s21_to_lower.o \
		s21_trim.o s21_to_upper.o s21_insert.o
OS := $(shell uname -s)

all:	clean s21_string.a test

s21_memchr.o:
	$(CC) $(CFLAGS) -c s21_memchr.c -o s21_memchr.o

s21_memcmp.o:
	$(CC) $(CFLAGS) -c s21_memcmp.c -o s21_memcmp.o

s21_memcpy.o:
	$(CC) $(CFLAGS) -c s21_memcpy.c -o s21_memcpy.o

s21_memmove.o:
	$(CC) $(CFLAGS) -c s21_memmove.c -o s21_memmove.o

s21_memset.o:
	$(CC) $(CFLAGS) -c s21_memset.c -o s21_memset.o

s21_strcat.o:
	$(CC) $(CFLAGS) -c s21_strcat.c -o s21_strcat.o

s21_strchr.o:
	$(CC) $(CFLAGS) -c s21_strchr.c -o s21_strchr.o

s21_strcmp.o:
	$(CC) $(CFLAGS) -c s21_strcmp.c -o s21_strcmp.o

s21_strcpy.o:
	$(CC) $(CFLAGS) -c s21_strcpy.c -o s21_strcpy.o

s21_strcspn.o:
	$(CC) $(CFLAGS) -c s21_strcspn.c -o s21_strcspn.o

s21_strerror.o:
	$(CC) $(CFLAGS) -c s21_strerror.c -o s21_strerror.o

s21_strlen.o:
	$(CC) $(CFLAGS) -c s21_strlen.c -o s21_strlen.o

s21_strncat.o:
	$(CC) $(CFLAGS) -c s21_strncat.c -o s21_strncat.o

s21_strncmp.o:
	$(CC) $(CFLAGS) -c s21_strncmp.c -o s21_strncmp.o

s21_strncpy.o:
	$(CC) $(CFLAGS) -c s21_strncpy.c -o s21_strncpy.o

s21_strpbrk.o:
	$(CC) $(CFLAGS) -c s21_strpbrk.c -o s21_strpbrk.o

s21_strrchr.o:
	$(CC) $(CFLAGS) -c s21_strrchr.c -o s21_strrchr.o

s21_strspn.o:
	$(CC) $(CFLAGS) -c s21_strspn.c -o s21_strspn.o

s21_strstr.o:
	$(CC) $(CFLAGS) -c s21_strstr.c -o s21_strstr.o

s21_strtok.o:
	$(CC) $(CFLAGS) -c s21_strtok.c -o s21_strtok.o

s21_sprintf.o:
	$(CC) $(CFLAGS) -c s21_sprintf.c -o s21_sprintf.o

s21_to_lower.o:
	$(CC) $(CFLAGS) -c s21_to_lower.c -o s21_to_lower.o

s21_trim.o:
	$(CC) $(CFLAGS) -c s21_trim.c -o s21_trim.o

s21_to_upper.o:
	$(CC) $(CFLAGS) -c s21_to_upper.c -o s21_to_upper.o

s21_insert.o:
	$(CC) $(CFLAGS) -c s21_insert.c -o s21_insert.o

s21_string.a: $(OFILE)
	ar rcs s21_string.a $(OFILE)
	cp s21_string.a libs21_string
	cp s21_string.a ls21_string


test: s21_string.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) test.c s21_string.a -o test -lcheck
	./test
else
	$(CC) $(CFLAGS) test.c s21_string.a -o test -lcheck -lsubunit -lrt -lpthread -lm
	./test
endif

gcov:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(FLAG) $(CFILE) $(LCOV) -o test -lcheck
else
	$(CC) $(CFLAGS) $(FLAG) $(CFILE) $(LCOV) -o test -lcheck -lsubunit -lrt -lpthread -lm
endif

gcov_report: gcov
	./test
	lcov -t “test” -o test.info -c -d .
	genhtml -o report test.info

open:
	open report/index.html

clean:
	rm -rf *o libs21_string *.gc* report *.a ls21_string test

re: gcov_report

cpp:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.h *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	rm -rf CPPLINT.cfg

# strncat, strchr, strcmp, strcpy, strncpy, strerror, strrchr, strstr, strtok
