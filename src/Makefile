CC = gcc
FLAG_C = -c
FLAG_O = -o
FLAG_COV = --coverage 
FLAG_ER = -Wall -Werror -Wextra -std=c11
s21_STRING_C = s21_*.c 
s21_STRING_O = s21_*.o
add_STRING_C = add_*.c
add_STRING_O = add_*.o
SUITE_CASES_C = case_*.c
SUITE_CASES_O = case_*.o
UNAME_S := $(shell uname -s)

ifeq (${UNAME_S}, Linux)
	TEST_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
	OPEN_CMD = xdg-open
else
	TEST_FLAGS = -lcheck
	OPEN_CMD = open
endif

all: clean s21_string.a test gcov_report

s21_string.a:
	$(CC) $(FLAG_C) $(FLAG_ER) $(s21_STRING_C)  ${add_STRING_C}
	ar rc s21_string.a $(s21_STRING_O) ${add_STRING_O}
	ranlib s21_string.a

test: s21_string.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c
	$(CC) $(ASAN) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests s21_string.a $(SUITE_CASES_O) $(s21_STRING_C) main.o ${TEST_FLAGS}
	./tests

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN_CMD) report/index.html

check:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests

clang-format:
	find . -name "*.c" -or -name "*.h" | xargs clang-format -i -style=Google

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./tests

clean:
	rm -rf *.o *.gcda *.gcno report s21_string.a test.info tests
	