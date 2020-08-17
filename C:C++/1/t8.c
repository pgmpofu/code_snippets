#include <stdio.h>

int num = 0;
int input = 0;
int i = 0;

int main(void)
{
  int dimensions[3];
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
  int breadth = dimensions[1];

  for (int y = 1; y <= breadth; y++)
  {
    for (int x = 1; x <= width; x++)
    {
      if (x == 1 || x == width || y == 1 || y == breadth)
      {
        printf("%s", "#");
      }
      else
      {
        printf("%s", ".");
      }
    }

    printf("%s\n", "");
  }

  return 0;
}
