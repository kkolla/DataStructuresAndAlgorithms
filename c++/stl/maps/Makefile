CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: mapOfMaps

mapOfMaps:
	$(CC) $(CFLAGS) -o mapOfMaps mapOfMaps.cc

clean:
	-rm -rf *.dS*
	-rm -f *.o mapOfMaps
