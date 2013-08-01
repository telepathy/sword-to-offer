#include <cstdio>
int findMin(int*,int);
int seqSearch(int *,int,int);
int main()
{
  int a[]={1,1,1,0,1};
  int x=findMin(a,5);
  printf("%d",x);
  return 0;
}
int findMin(int *a,int len)
{
  int p1=0,p2=len-1;
  if (a[p1]<a[p2]) return a[0];
  while(p2-p1>1)
  {
    int m=(p1+p2)/2;
    if(a[p1]<a[m]) p1=m;
    else if(a[m]<a[p2]) p2=m;
    else 
    {
      return seqSearch(a,p1,p2);
    }
  }
  return a[p2];
}
int seqSearch(int *a,int p1,int p2)
{
  int min=a[p1];
  for(int i=p1+1;i<=p2;++i)
    if (min>a[i]) min=a[i];
  return min;
}