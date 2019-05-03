all : convert hw3testunits

convert : units.o convert.o
	g++ -std=c++14 -Wall units.o convert.o -o convert

units.o : units.cpp units.h
	g++ -std=c++14 -Wall -c units.cpp

convert.o : convert.cpp units.h
	g++ -std=c++14 -Wall -c convert.cpp

hw3testunits.o : hw3testunits.cpp testbase.h
	g++ -std=c++14 -Wall -c hw3testunits.cpp

hw3testunits: units.cpp testbase.cpp hw3testunits.cpp
	g++ -std=c++14 -Wall -Werror units.cpp testbase.cpp hw3testunits.cpp -o hw3testunits


clean :
	rm -f convert hw3testunits *.o *~
	rm -rf html

.PHONY: all clean
