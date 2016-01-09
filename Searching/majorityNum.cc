#include "search.h"

/*
 * Finds the majority number.
 */
int majorityNum(int input[], int len) {
    int element = -1, count = 0;
    for (int i = 0; i < len; i++) {
        if (count == 0) {
            element = input[i];
            count++;
            continue;
        }
        if (input[i] == element) {
            count++;
        } else {
            count--;
        }
    }
    return element;
}
