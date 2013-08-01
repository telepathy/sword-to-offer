#include <cstdio>
class IsOdd
{
public:
  bool operator() (int k)
  {
    return k%2;
  }
};
template <class T>
int work(int *,int,T);
int main()
{
  IsOdd io;
  int a[]={1,2,2,2,3,4,5,6,7,8,9,10};
  for(int i=0;i<12;++i)
    printf("%d ",a[i]);
  printf("\n");
  work(a,12,io);
  for(int i=0;i<12;++i)
    printf("%d ",a[i]);
}

template <class T>
int work(int *a,int size, T io)
{
  int l=0,r=size-1;
  while(l<r)
  {
    while(io(a[l])) ++l;
    while(!io(a[r])) --r;
    if(l<r)
    {
      int temp=a[r];
      a[r]=a[l];
      a[l]=temp;
    } 
  }
}