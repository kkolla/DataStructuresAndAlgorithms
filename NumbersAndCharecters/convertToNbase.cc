#include <iostream>
#include <string.h>
using namespace std;

string convert(uint32_t num, int base)
{
    string result;
    while (num != 0) {
        char ch = "0123456789ABCDEF"[num%base];
        result.insert(0, 1, ch);
        /*
         * C++ always tries to reallocate, if inserted.
         * we can always use std:: reserve to bypass this con.
         */
        num = num/base;
    }
    if (base == 16) {
        result.insert(0 ,"0x");
    }
    return result;
}

int main()
{
    cout<<convert(5, 2)<<endl;
    cout<<convert(12000, 16)<<endl; // Should be 0x2EE0
    return 0;
}
