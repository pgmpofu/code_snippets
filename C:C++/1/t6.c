#include <stdio.h>

float sum = 0;
float num = 0;
int input = 0;
int count = 0;
float min = 100000;
float max = - 100000;

int main(void) {
  while(input != EOF) {
    input = scanf("%f\n", &num);
    if(input == 1 && num >= - 100000 && num <= 100000) {
      sum+=num;
      count++;
    }

    if(max < num) {
      max = num;
    }

    if(min > num) {
      min = num;
    }
  }

  printf("%.2f %.2f %.2f\n",min, max, sum/count);
  return 0;
}
