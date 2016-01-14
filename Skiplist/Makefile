CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: strings

strings:
	$(CC) $(CFLAGS) -o skiplist skiplist.cc

clean:
	-rm -rf *.dS*
	-rm -f *.o skiplist
