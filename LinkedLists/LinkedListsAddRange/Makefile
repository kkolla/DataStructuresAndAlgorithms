CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: program

program:
	$(CC) $(CFLAGS) -o program program.cc

clean:
	-rm -rf *.dS*
	-rm -f *.o program
