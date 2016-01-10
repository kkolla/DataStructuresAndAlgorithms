#include "strings.h"
void permutations_(char *str, int index) {
    int len = strlen(str);
    if (index == len) {
        cout<<str<<endl;
        return;
    }
    for (size_t i = index; i < len; i++) {
        swap(str, index, i);
        permutations_(str, index+1);
        swap(str, index, i);
    }
}
void permutations(char *str) {
    if (str == NULL) return;
    if (strlen(str) == 1) {
        std::cout << str << std::endl;
        return;
    }
    if (strlen(str) == 2) {
        std::cout << str << std::endl;
        swap(str, 0, 1);
        std::cout << str << std::endl;
    }
    permutations_(str, 0);
}
