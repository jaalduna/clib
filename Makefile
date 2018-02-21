CFLAGS= -g -Wall -pedantic -std=c99
LDFLAGS= -g

all: test

test.o my_func.o: my_func.h

test: my_func.o test.o

clean:
	rm -f *.o
	rm -f test
