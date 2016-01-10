#include "strings.h"

string reverseStr(string str) {
    int i = 0, j = str.length() - 1;
    while (i < j) {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i++;
        j--;
    }
    return str;
}
