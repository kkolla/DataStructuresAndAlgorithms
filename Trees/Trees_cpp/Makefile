# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

OBJECTS = tree.o bst.o

default: tree bst

%.o: %.cc
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -rf *.dS*
	-rm -f *.o bst tree
