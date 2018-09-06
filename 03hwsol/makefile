GPP = g++ -O3 -Wall -std=c++11

calc: main.cc main.h point2d.o vector2d.o
	$(GPP) -o calc main.cc point2d.o vector2d.o

point2d.o: point2d.cc point2d.h vector2d.o
	$(GPP) -o point2d.o -c point2d.cc

vector2d.o: vector2d.cc vector2d.h
	$(GPP) -o vector2d.o -c vector2d.cc

test_point2d: test_point2d.o point2d.o vector2d.o
	$(GPP) -o test_point2d test_point2d.o point2d.o vector2d.o; \
	clear; \
	./test_point2d;

test_point2d.o: test_point2d.cc test_point2d.h point2d.o vector2d.o
	$(GPP) -o test_point2d.o -c test_point2d.cc vector2d.o

test_vector2d: test_vector2d.o vector2d.o
	$(GPP) -o test_vector2d test_vector2d.o vector2d.o; \
	clear; \
	./test_vector2d;

test_vector2d.o: test_vector2d.cc test_vector2d.h vector2d.o
	$(GPP) -o test_vector2d.o -c test_vector2d.cc

clean:
	rm calc &
	rm point2d.o &
	rm vector2d.o &
	rm test_point2d.o &
	rm test_vector2d.o &
	rm test_point2d &
	rm test_vector2d &
	clear

