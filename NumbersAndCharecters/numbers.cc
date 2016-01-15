#include "numberAndCharecters.h"
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
int main() {
    //testEndian();
    test64BitOperations();
    cout<<endl;
    return 0;
}
