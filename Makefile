# Makefile

CXX_FLAG = --std=c++11 -g

all: runMovies tests

runMovies: main.o movies.o
	g++ $(CXX_FLAG) -o runMovies main.o movies.o

tests: tests.o movies.o
	g++ $(CXX_FLAG) -o tests tests.o movies.o
	./tests

movies.o: movies.cpp
	g++ -c $(CXX_FLAG) movies.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

tests.o: tests.cpp
	g++ -c $(CXX_FLAG) tests.cpp

clean:
	rm -f runMovies tests *.o