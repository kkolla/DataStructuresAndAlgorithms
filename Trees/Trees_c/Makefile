OBJECTS = tree.o

default: tree

%.o: %.c
	gcc -g -c $< -o $@

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f *.o tree
