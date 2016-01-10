#include "strings.h"

string removeDuplicates(string str) {
    int counter = 0, i = 0, j = 0;
    while (counter < str.length()) {
        char ch = str[counter];
        i = counter + 1;
        j = counter + 1;
        while (i < str.length()) {
            if (str[i] != ch) {
                str[j] = str[i];
                j++;
            }
            i++;
        }
        str.erase(j, str.length());
        counter++;
    }
    return str;
}
