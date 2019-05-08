all : test


rational.o : rational.cpp rational.h
	g++ -std=c++14 -Wall -c rational.cpp

testbase.o : testbase.cpp testbase.h
	g++ -std=c++14 -Wall -c testbase.cpp

test-rational.o : test-rational.cpp testbase.h rational.h
	g++ -std=c++14 -Wall -c test-rational.cpp

test: rational.o testbase.o test-rational.o
	g++ -std=c++14 -Wall -Werror rational.o testbase.o test-rational.o -o test


clean :
	rm -f test *.o *~

.PHONY: all clean
