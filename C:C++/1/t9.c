#include <stdio.h>
#include <math.h>

int num = 0;
int input = 0;
int i = 0;

int main(void)
{
	int dimensions[3];
	//Read input from user
	while (input != EOF && i < 3)
	{
		input = scanf(" %d", &num);
		if (input == 1 && num >= 0 && num <= 50)
		{
			dimensions[i] = num;
			i++;
		}
	}

	int width = dimensions[0];
	int height = dimensions[2];

	// Draw sloping lines
	for (int i = height - 1; i >= 0; i--)
	{
		int left = floor(i * (width / (2.0 * height)));
		int right = ceil((width - 1) + -i * (width / (2.0 * height)));
		for (int j = 0; j <= width; j++)
		{
			if (j < left)
			{
				printf(" ");
			}

			else if (left == j || right == j)
			{
				printf("#");
			}

			else if (j > right)
			{
				continue;
			}

			else
			{
				if (i == 0 || i == height - 1)
				{
					printf("#");
				}

				else
				{
					printf(".");
				}
			}
		}

		printf("\n");
	}
	return 0;
}
