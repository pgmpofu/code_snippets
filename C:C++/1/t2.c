#include <stdio.h>

int main(void) {

	printf("%lu ", sizeof(char) * 8);
	printf("%lu ", sizeof(unsigned char) * 8);
	printf("%lu ", sizeof(int) * 8);
	printf("%lu ", sizeof(unsigned int) * 8);
	printf("%lu ", sizeof(long) * 8);
	printf("%lu ", sizeof(unsigned long) * 8);
	printf("%lu ",  sizeof(float) * 8);
	printf("%lu ", sizeof(double) * 8);
	printf("%lu\n", sizeof(long double) * 8);
}