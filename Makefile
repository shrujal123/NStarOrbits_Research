all: test

test: test.o header.o
	g++ -o test test.o header.o

header.o: header.cpp header.h
	g++ -c header.cpp

test.o: test.cpp
	g++ -c test.cpp
