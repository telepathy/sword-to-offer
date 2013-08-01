#include <cassert>
#include <iostream>
using namespace std;

template<typename T>
class multipleMatrix{
private:
  T *data;
public:
  int r,c;
  multipleMatrix(T *initdata,int x=0,int y=0):r(x),c(y)
  {
    data=new T [r*c];
    init(initdata);
  }
  multipleMatrix(const multipleMatrix& m):r(m.r),c(m.c){
    data=new T [r*c];
    init(m.data);
  }
  multipleMatrix& operator=(const multipleMatrix& m){
    if (this==&m) return *this;
    delete []data;
    c=m.c;
    r=m.r;
    data=new T [r*c];
    init(m.data);
    return *this;
  }
  ~multipleMatrix()
  {
    if(data)
    {
      delete []data;
    }
  }
  void init(T *a){
    for(int i=0;i<r;++i)
      for(int j=0;j<c;++j)
        data[i*c+j]=a[i*c+j];
  }
  T get(int x,int y) const{return data[x*c+y];}
  void set(int x,int y,T v){data[x*c+y]=v;}
  multipleMatrix<T>& operator*=(const multipleMatrix<T>&);
};

template<typename T>
const multipleMatrix<T> operator *(const multipleMatrix<T>& a, const multipleMatrix<T>& b)
{
  assert(a.c==b.r);
  int cnt=a.c;
  int r=a.r;
  int c=b.c;
  T *d=new T[r*c];
  for(int i=0;i<r;++i)
    for(int j=0;j<c;++j)
    {
      T sum=0;
      for(int k=0;k<cnt;++k)
        sum+=(a.get(i,k)*b.get(k,j));
      d[i*c+j]=sum;
    }
  return multipleMatrix<T>(d,r,c);
}

template<typename T>
ostream& operator << (ostream& os,const multipleMatrix<T>& m)
{
  for(int i=0;i<m.r;++i)
  {
    for (int j=0;j<m.c;++j)
      os<<m.get(i,j)<<" ";
    os<<endl;
  }
  return os;
}