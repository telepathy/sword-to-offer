#include <cstdio>
int printMatrix(int*,int,int);
int printCircle(int*,int,int,int,int,int);
int main()
{
  int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  printMatrix(a,1,1);
}
int printMatrix(int* a,int r,int c)
{
  for(int i=0;i*2<c && i*2<r;++i)
  {
    printCircle(a,i,i,r-i-1,c-i-1,c);
  }
}
int printCircle(int* m,int x1,int y1,int x2,int y2,int c)
{
  for(int i=y1;i<=y2;++i) printf("%d ",m[x1*c+i]);//m[x1,i]
  if(x2>x1)
  {  
    for(int i=x1+1;i<=x2;++i) printf("%d ",m[i*c+y2]);//m[i,y2]
    if(y2>y1)
    {
      for(int i=y2-1;i>=y1;--i) printf("%d ",m[x2*c+i]);//m[x2,i]
      if(x2-x1>1)
        for(int i=x2-1;i>x1;--i) printf("%d ",m[i*c+y1]);//m[i,y1]
    }
  } 
}