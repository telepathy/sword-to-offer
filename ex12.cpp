#include <cstdio>
void printdigit(int);
void pr(int *,int,int,bool);
int main()
{
  int k;
  scanf("%d",&k);
  printdigit(k);
  return 0;
}
void printdigit(int k)
{
  for(int i=1;i<=k;++i)
  {
    int *arr=new int[k];
    pr(arr,i,i,true);
    delete [] arr;
  }
}
void pr(int *arr,int left,int total,bool first)
{
  if (left==0)
  {
    for (int i=0;i<total;++i) printf("%d",arr[i]);
    printf("\n");
    return;
  }
  if(!first)
  {
    arr[total-left]=0;
    pr(arr,left-1,total,false);
  }
  for(int i=1;i<=9;++i)
  {
    arr[total-left]=i;
    pr(arr,left-1,total,false);
  }
}