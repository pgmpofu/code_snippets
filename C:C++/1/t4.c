#include <stdio.h>
#include <math.h>

int main(void)
{
	float num = 0;
	float input = scanf("%f\n", &num);
	if (input == 1)
	{
		printf("%.0f ", floor(num));
		printf("%.0f ", round(num));
		printf("%.0f\n", ceil(num));
	} else {
		printf("scanf error: (%.0f)\n", input);
	}

	return 0;
}