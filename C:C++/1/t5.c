#include <stdio.h>
#include <math.h>
int main(void)
{
	float num = 0;
	int input = 0;

	while (input != EOF)
	{
		input = scanf("%f", &num);
		if (input == 1)
		{
			printf("%.0f ", floor(num));
			printf("%.0f ", round(num));
			printf("%.0f\n", ceil(num));
		}
	}

	printf("%s\n", "Done.");

	return 0;
}
