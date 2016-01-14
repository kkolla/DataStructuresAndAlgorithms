CC = g++
C = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: combinations_sizeCfrom_list_sizeN multiply2numbers regexMatch
.PHONY : all

combinations_sizeCfrom_list_sizeN:
	$(C) $(CFLAGS) -o combinations_sizeCfrom_list_sizeN combinations_sizeCfrom_list_sizeN.c

regexMatch:
	$(CC) $(CFLAGS) -o regexMatch regexMatch.cc

multiply2numbers:
	$(C) $(CFLAGS) -o multiply2numbers multiply2numbers.c

clean:
	-rm -rf *.dS*
	-rm -f *.o multiply2numbers combinations_sizeCfrom_list_sizeN regexMatch
