my_testall : my_test testbase

my_test : rational.o my_test.o
	g++ -std=c++14 -Wall -Werror rational.o my_test.o -o my_test

rational.o : rational.cpp rational.h
	g++ -std=c++14 -Wall -c rational.cpp

my_test.o : my_test.cpp rational.h
	g++ -std=c++14 -Wall -c my_test.cpp

testbase.o : testbase.cpp testbase.h
	g++ -std=c++14 -Wall -c testbase.cpp

testbase: rational.o testbase.o
	g++ -std=c++14 -Wall -Werror rational.o testbase.o -o testbase


clean :
	rm -f my_test *.o *~
	rm -rf html

.PHONY: all clean
