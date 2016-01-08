OBJECTS = sll.o reverseRecursive.o fillNodes.o

default: sll reverseRecursive fillNodes

%.o: %.c
	gcc -g -c $< -o $@

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f *.o sll reverseRecursive fillNodes
