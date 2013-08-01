#include <cstdio>
#include <vector>
using namespace std;
template <class T>
class MinStack
{
private:
  std::vector<T> data;
  std::vector<int> min;
public:
  void push(const T& t)
  {
    if((data.empty())||(t<data[min.back()]))
      min.push_back(data.size());
    data.push_back(t);
  }
  T pop()
  {
    if(min.back()==(data.size()-1))
      min.pop_back();
  }
  T& minEle()
  {
    return data[min.back()];
  }
};
int main()
{
  MinStack<int> m;
  m.push(2);
  m.push(3);
  m.push(1);
  printf("%d\n",m.minEle());
  m.pop();
  printf("%d\n",m.minEle());
  return 0;
}