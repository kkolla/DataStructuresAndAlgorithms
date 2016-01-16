#include "numberAndCharecters.h"

int* multiply(int *A, int m, int *B, int n) {
    int outLen = m+n;
    int *output = new int[outLen - 1];
    memset(output, 0, outLen*sizeof(int));
    int shift = outLen - 1;


    for (int i = n-1; i >= 0; i--) {
        int s = shift;
        int carry = 0;
        for (int j = m-1; j >= 0; j--) {
            int product = (B[i] * A[j]) + carry + output[s];
            output[s] = product % 10;
            carry = product / 10;
            s--;
        }
        output[s] = output[s] + carry;
        shift--;
    }
    return output;
}
