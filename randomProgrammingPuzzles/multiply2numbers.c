#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* multiplyTwoNumber(int* A, int m, int* B, int n)
{
	int i, j, shift, carry, len = m + n;
	int *output;
	int s = len - 1;
	int sum, product;

	output = (int*)malloc(len * sizeof(int));
	memset(output, 0, len);

	for(j = m-1; j >= 0; j--) {
		carry = 0;
		shift = s;
		for (i = n-1; i >= 0; i--) {
			product = A[j] * B[i];
			sum = product + output[shift] + carry;
			output[shift] = sum % 10;
			carry = sum / 10;
			shift--;
		}
		output[shift] = output[shift] + carry;
		s--;
	}
	return output;
}

int main() {
	int i;
	int one[2] = {5,0};
	int two[2] = {1,2};
	int* res = multiplyTwoNumber(one, 2, two, 2);
	for (i = 0; i < 4; ++i) {
		printf("%d", res[i]);
	}
	printf("\n");
	return 0;
}
