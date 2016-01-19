CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: numbers charecters convertToNbase

charecters:
	$(CC) $(CFLAGS) -o charecters charecters.cc longestSubstringNoRepeatChars.cc

numbers:
	$(CC) $(CFLAGS) -o numbers numbers.cc multiply.cc squareroot.cc

convertToNbase:
	$(CC) $(CFLAGS) -o convertToNbase convertToNbase.cc

clean:
	-rm -rf *.dS*
	-rm -f *.o numbers charecters convertToNbase
