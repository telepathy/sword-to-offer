#include <iostream>
#include "multipleMatrix.h"
using namespace std;
unsigned long long calcFab(unsigned int);
int main()
{
  unsigned int n;
  cin>>n;
  cout<<calcFab(n);
  return 0;
}
unsigned long long calcFab(unsigned int x)
{
  unsigned long long aa[]={1,1,1,0};
  unsigned long long bb[]={1,0,0,1};
  unsigned int k=x-1;
  multipleMatrix<unsigned long long> base(aa,2,2);
  multipleMatrix<unsigned long long> ret(bb,2,2);
  int l=0;
  while (k>0)
  {
    k>>=1;
    ++l;
  }
  k=x-1;
  unsigned int mask=1;
  for (int i=0;i<l;++i)
  {
    if (mask&k) ret=ret*base;
    k>>=1;
    base=base*base;
  }

  return ret.get(0,0);
}
