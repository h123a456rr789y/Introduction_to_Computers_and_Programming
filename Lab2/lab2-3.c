#include<stdio.h>
int main(void)
{
  float r1,r2,h;
  float volume;

  printf("Value of r1:");
  scanf("%f", &r1);

  printf("Value of r2:");
  scanf("%f", &r2);

  printf("Value of h:");
  scanf("%f",&h);

  volume=h*3.1415926/3*(r1*r1+r2*r2+r1*r2);

  printf("Volume:%f",volume);

  return 0;
}
