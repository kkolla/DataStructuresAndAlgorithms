#include "search.h"

/*
 * Given an array which contains numbers [0,1,2] in arbitrary order, this
 * function arranges them
 * input - the Input array
 * n - Length of the input array
 */
int dutchNationalFlag(int input[], int n) {
    int i = 0, pos0 = 0, pos2 = n-1;

    while (input[i] == 0) {
        i++;
        pos0++;
    }
    while (input[pos2] == 2) pos2--;
    while (i < n) {
        if (input[i] == 0) {
            input[i] = input[pos0];
            input[pos0] = 0;
            pos0++;
        }
        if (input[i] == 2 && i < pos2) {
            input[i] = input[pos2];
            input[pos2] = 2;
            pos2--;

            /*
             * Consider this situation
             * 0   1   2    1    0    2
             *   pos0  i       pos2
             * Here, we swap i with pos2
             * 0   1   0    1    2    2
             *   pos0  i   pos2
             * we should not move i, we should handle i.
             * I therefore do an i--;
             */
            i--;
        }
        i++;
    }
    showArray(input, n);
    return 0;
}
