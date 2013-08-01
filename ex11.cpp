#include <cstdio>
#include <cmath>
#define EPV 0.00000001
double power(double,int);
bool eq(double,double);
double power_n(double,unsigned int);
int main()
{
  double base;
  int exponent;
  scanf("%lf%d",&base,&exponent);
  printf("%lf",power(base,exponent));
  return 0;
}
bool eq(double x1,double x2)
{
  return abs(x1-x2)<=EPV?true:false;
}
double power_n(double base, unsigned int exponent)
{
  double result=1.0;
  unsigned int mask=1;
  while(exponent)
  {
    if(exponent & mask) result*=base;
    base*=base;
    exponent>>=1;
  }
  return result;
}
double power(double base, int exponent)
{
  if (eq(base,0))
  {
    if (exponent<1)
    {
      printf("error\n");
      return 0.0;
    }
    else
    {
      return 0.0;
    }
  }
  else if (exponent==0) return 1.0;
  else if (exponent>0) return power_n(base,exponent);
  else if (exponent<0) return 1.0/power_n(base,0-exponent);
}