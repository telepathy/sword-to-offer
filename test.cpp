#include <cstdio>
void test(int *);
int main()
{
  int k=65536;
  int *p;
  p=&k;
  test(p);
  printf("%d",*p);
  return 0;
}
void test(int *p)
{
  if (p=NULL)
    return;
  printf("%d",p);
}