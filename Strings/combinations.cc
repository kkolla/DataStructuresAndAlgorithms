#include "strings.h"
void combinations_(char *str, int start, int depth, char* combis) {
    int len = strlen(str);
    for (size_t i = start; i < len; i++) {
        combis[depth] = str[i];
        combis[depth+1] = '\0';
        std::cout << combis << std::endl;
        if (i < len-1) {
            combinations_(str, i+1, depth+1, combis);
        }
    }
}

void combinations(char *str) {
    int len = strlen(str);
    char *combis = new char[len];
    memset(combis, '\0', len);
    combinations_(str, 0, 0, combis);
}
