// constcast.cpp -- const_cast<>를 사용한다
#include <iostream>
using std::cout;
using std::endl;

void change(const int * pt, int n);

int main(void)
{
  int pop1 = 38383;
  const int pop2 = 2000;

  cout<<"pop1, pop2 :"<<pop1<<", "<<pop2<<endl;
  change(&pop1, -103);
  change(&pop2, -103);
  cout<<"pop1, pop2 :"<<pop1<<", "<<pop2<<endl;

  return 0;
}

void change(const int * pt, int n)
{
  int * pc;
  pc = const_cast<int *>(pt);
  *pc += n;
}