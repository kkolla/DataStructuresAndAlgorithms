#include <iostream>
#include <math.h>
#include <limits.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"
using namespace std;
/* Print n as a binary number */
void printbitssimple(uint8_t n) {
	unsigned int i;
	i = 1<<(sizeof(n) * 8 - 1);

	while (i > 0) {
		if (n & i)
			printf("1");
		else
			printf("0");
		i >>= 1;
	}
}
