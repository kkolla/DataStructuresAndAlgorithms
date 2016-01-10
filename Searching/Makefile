CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: search occurrance
.PHONY : all

search:
	$(CC) $(CFLAGS) -o search search.cc majorityNum.cc dutchNationalFlag.cc

occurrance:
	$(CC) $(CFLAGS) -o occurrance occurrance.cc

clean:
	-rm -rf *.dS*
	-rm -f *.o search occurrance
