GPP = g++ -O3 -Wall -std=c++11


test_frac: test_fraction.h test_fraction.cc fraction.o
	$(GPP) -o test_frac test_fraction.h test_fraction.cc fraction.o

fraction.o: fraction.h fraction.cc
	$(GPP) -o fraction.o -c fraction.cc

clean:
	rm test_frac &
	rm fraction.o &
