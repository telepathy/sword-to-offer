#include <cstdio>
class C{
public:
  C(){};
  virtual ~C(){};
};
int main(void){
  C c;
  printf("%d\n",sizeof(c));
  return 0;
}