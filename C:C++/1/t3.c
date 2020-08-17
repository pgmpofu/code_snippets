#include <stdio.h>
#include <math.h>

int main(void)
{
	float num = 0;
	scanf("%f", &num);
	printf("%.0f ", floor(num));
	printf("%.0f ", round(num));
	printf("%.0f\n", ceil(num));
	return 0;
}