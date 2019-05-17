all : test


matrix.o : matrix.cpp matrix.h
	g++ -std=c++14 -Wall -c matrix.cpp

testbase.o : testbase.cpp testbase.h
	g++ -std=c++14 -Wall -c testbase.cpp

test-matrix.o : test-matrix.cpp testbase.h matrix.h
	g++ -std=c++14 -Wall -c test-matrix.cpp

test: matrix.o testbase.o test-matrix.o
	g++ -std=c++14 -Wall -Werror matrix.o testbase.o test-matrix.o -o test


clean :
	rm -f test *.o *~

.PHONY: all clean
