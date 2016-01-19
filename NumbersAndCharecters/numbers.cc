#include "numberAndCharecters.h"
void printbitssimple(uint8_t n) {
	unsigned int i;
	i = 1<<(sizeof(n) * 8 - 1);

	while (i > 0) {
		if (n & i)
			printf("1");
		else
			printf("0");
		i >>= 1;
	}
}

/*
 * Doesnt print zeroes in the higher order bits
 */
void printBinaryRecurse(uint8_t number)
{
    // std::cout << unsigned(number) << " - ";
    if (number == 0)
    {
        cout << "0";
        return;
    }
    uint8_t bit = number & 0x01;
    cout<<unsigned(bit);
    number = number >> 1;
    printBinaryRecurse(number);
}

void printBinary(uint8_t number)
{
    for (int i = 0; i < 8; i++) {
        if (number & (1 << (7-i))) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
}

void test64BitOperations() {
    uint64_t number = 0x0001020304050607;
    uint8_t *ptr = (uint8_t *)&number;

    for (int i = 0; i < 8; i++) {
        printbitssimple(ptr[i]);
        cout<<endl;
    }
}

inline int isLittleEndian(uint32_t val)
{
    char *ptr = (char *)&val;
    return(*ptr & 1);
}
void testEndian() {
    uint32_t val = 1;
    cout<<"This machine is ";
    isLittleEndian(val) ? printf(KBLU "LITTLE" RESET) : printf(KBLU "BIG" RESET);
    cout<<" Endian\n";
    char *ptr = (char *)&val;
    cout<<"Little Endian Representation of Value 01 inside an integer of 4 bytes\n";
    printf(KRED"%p   "RESET, ptr);
    printf(KRED"%p   "RESET, ptr+1);
    printf(KRED"%p   "RESET, ptr+2);
    printf(KRED"%p\n"RESET, ptr+3);
    printf(KBLU"\t%d   "RESET, *ptr);
    printf(KBLU"\t\t%d   "RESET, *(ptr+1));
    printf(KBLU"\t\t%d   "RESET, *(ptr+2));
    printf(KBLU"\t\t%d   "RESET, *(ptr+3));
    printf(KYEL"");
    cout<<"\n   ";
    printBinary(*ptr);
    cout<<"\t    ";
    printBinary(*(ptr+1));
    cout<<"\t     ";
    printBinary(*(ptr+2));
    cout<<"\t      ";
    printBinary(*(ptr+3));
    printf(RESET"");
    cout<<KGRN"\nNotice the addresses and values stores at that addresses\n"RESET;
}
void multiplyTest()
{
    int a[] = {9,9,9};
    int b[] = {9,9};
    int *res = multiply(a, 3, b, 2);
    for (size_t i = 0; i < 5; i++) {
        cout<<res[i];
    }
    free(res);
}
void squareRootTest()
{
	cout<<squareroot(0.2) <<endl;
	cout<<squareroot(1)   <<endl;
	cout<<squareroot(2.0) <<endl;
	cout<<squareroot(3.0) <<endl;
	cout<<squareroot(4.0) <<endl;
	cout<<squareroot(5.0) <<endl;
	cout<<squareroot(6.0) <<endl;
	cout<<squareroot(7.0) <<endl;
	cout<<squareroot(8.0) <<endl;
	cout<<squareroot(9.0) <<endl;
	cout<<squareroot(10.0)<<endl;
}
int main() {
	squareRootTest();

	//multiplyTest();
    //testEndian();
    //test64BitOperations();

    cout<<endl;
    return 0;
}
