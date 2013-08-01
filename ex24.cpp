#include <cstdio>
bool check(int*,int);
int main()
{
  int a[]={5,7,6,9,11,10,8};
  int b[]={7,4,6,5};
  printf("%d %d",check(a,7),check(b,4));
  return 0;
}
bool check(int *a,int l)
{
  if(l<=1) return true;
  int root=a[l-1];
  int i=0;
  while(a[i]<root) ++i;
  bool flag=true;
  for(int j=i;j<l-1;++j)
    if(a[j]<root)
    {
      flag=false;
      break;
    }
  if(flag)
    return check(a,i) && check(&a[i],l-i-1);
  else 
    return false;
}
