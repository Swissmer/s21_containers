CFLAGS = -Wall -Werror -Wextra -std=c++17
OS = $(shell uname)


ifeq ($(OS), Linux)
	CHECK_FLAGS = -L/path/to/gtest/lib -lgtest -lstdc++
	MEM_CHECK = valgrind --tool=memcheck --trace-children=yes --track-origins=yes --leak-check=full
else
	CHECK_FLAGS = -lgtest # -lstdc++
	MEM_CHECK = leaks --atExit --
endif

all: clean
	g++ $(CFLAGS) s21_test.cc $(CHECK_FLAGS) -lm -pedantic -o test

change_style:
	find . \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0 clang-format -i -style=Google

style:
	find . \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0 clang-format -n -style=Google

test: clean
	g++ $(CFLAGS) s21_test.cc $(CHECK_FLAGS) -lm -pedantic -o test
	./test

gcov_report: clean
	g++ -std=c++17 -Wall -Werror -Wextra $(CPP_FLAGS) --coverage s21_test.cc -o gcov_report  -lgtest
	chmod +x *
	./gcov_report
	lcov -t "gcov_report" -o gcov_report.info --no-external --ignore-errors mismatch -c -d .
	genhtml -o report/ gcov_report.info
	open ./report/index.html

leaks: test
	CK_FORK=no $(MEM_CHECK) ./test -pedantic
	make clean

clean:
	rm -rf *.o *.a test *.gcda *.gcno gcov_report *.info report

rebuild:
	make clean
	make set
