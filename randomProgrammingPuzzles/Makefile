OBJECTS = Int_to_Binary.o multiply2numbers.o combinations_sizeCfrom_list_sizeN.o

default: Int_to_Binary multiply2numbers combinations_sizeCfrom_list_sizeN

%.o: %.c
	gcc -g -c $< -o $@

program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f Int_to_Binary combinations_sizeCfrom_list_sizeN multiply2numbers
