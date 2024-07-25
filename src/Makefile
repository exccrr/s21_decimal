USERNAME=$(shell users)
BRANCH_NAME=$(shell git branch | grep "*" | sed "s/^.//" | sed "s/^.//")

CC= gcc
FLAGS= -Wall -Wextra -Werror -std=c11 -g
PKG_CONFIG =$(shell pkg-config --libs --cflags check)
GCOV= -fprofile-arcs -ftest-coverage
INFO= coverage.info

all: clean s21_decimal.a test gcov_report

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.h ./tests/*.c *.h
	clang-format -i ./functions/*.c *.h
	clang-format -i ./additional_functions/*.c *.h
	rm -f .clang-format

s21_decimal.a:
	$(CC) $(FLAGS) -c ./additional_functions/*.c ./functions/*.c
	ar rc s21_decimal.a *.o
	ranlib s21_decimal.a
	rm -rf *.o

test: clean
	$(CC) $(FLAGS) -o s21_decimal_test ./additional_functions/*.c ./functions/*.c ./tests/test.c $(PKG_CONFIG)  -lcheck -lm -lsubunit 
	./s21_decimal_test

te: clean s21_decimal.a
	$(CC) $(FLAGS) -o test me.c s21_decimal.a
	./test

gcov_report:
	$(CC) $(FLAGS) $(GCOV) -o gcov_main ./additional_functions/*.c ./functions/*.c ./tests/test.c $(PKG_CONFIG)
	./gcov_main
	lcov -t "gcov_main" -c -d ./ --output-file $(INFO)
	genhtml $(INFO) --output-directory ./coverage
	$(MAKE) open
	rm -rf *.gcda *.gcno *.info

clean:
	rm -rf res_leak.txt *.gcda *.gcno *.info *.a *.dSYM gcov_main s21_decimal_test coverage test

open:
	open coverage/index.html

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=res_leak.txt ./s21_decimal_test
