#include <cstdio>
union u{
  int si;
  unsigned int ui; 
};
int solve(unsigned int x)
{
  int ret=0;
  while(x)
  {
    ret+=x%2;
    x>>=1;
  }
  return ret;
}
int main()
{
  int x;
  u temp;
  scanf("%d",&temp.si);
  printf("%d\t%d\t%d",temp.si,temp.ui,solve(temp.ui));
  return 0;
}