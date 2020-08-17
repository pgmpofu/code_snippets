#include <stdio.h>

int num = 0;
int input = 0;

int main(void)
{
	input = scanf("%d", &num);
	while (input != EOF)
	{
		if (input == 1)
		{
			for (int i = 0; i < num; i++)
			{
				printf("%s", "#");
			}
			printf("\n");
		}
		input = scanf("%d", &num);
	}
	return 0;
}
