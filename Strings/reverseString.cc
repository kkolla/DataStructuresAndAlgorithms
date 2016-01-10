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
void reverseStr(char* str, int begin, int end)
{
    char ch;
    if (end >= begin) return;
    while (begin < end) {
        ch = str[begin];
        str[begin] = str[end];
        str[end] = ch;
    }
}
