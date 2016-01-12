# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: list

list:
	$(CC) $(CFLAGS) -o list list.cc sortList.cc listUtil.cc reverseMerge.cc

clean:
	-rm -rf *.dS*
	-rm -f *.o list
