OBJECTS = stack.o

default: stack

%.o: %.c
	gcc -g -c $< -o $@

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f *.o stack
