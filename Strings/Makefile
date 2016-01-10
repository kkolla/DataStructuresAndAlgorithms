CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: strings

strings:
	$(CC) $(CFLAGS) -o strings strings.cc reverseString.cc removeDuplicates.cc

clean:
	-rm -rf *.dS*
	-rm -f *.o strings
