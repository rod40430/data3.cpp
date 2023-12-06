// tempparm.cpp -- 템플릿 매개변수를 사용하는 템플릿
#include <iostream>
#include "stacktp.hpp"

template <template <typename T> class Thing>
class Crad
{
private:
  Thing<int> s1;
  Thing<double> s2;
public:
  Crad() {};
  // Thing 클래스가 push()와 pop() 멤버를 가지고 있다고 가정한다
  bool push(int & a, double & x) {return s1.push(a) && s2.push(x);}
  bool pop(int & a, double & x) {return s1.pop(a) && s2.pop(x);}
};

int main(void)
{
  using std::cout;
  using std::cin;
  using std::endl;

  Crad<Stack> nebula;
// Stack은 template <typename T> class Thing과 일치해야 한다
  int ni;
  double nb;
  cout<<"4 3,5와 같이 int double 쌍을 입력하라(끝내려면 0 0) : \n";

  while (cin>>ni>>nb && ni > 0 && nb > 0)
    {
      if (!nebula.push(ni, nb))
        break;
    }

  while (nebula.pop(ni, nb))
    cout<<ni<<", "<<nb<<endl;
  cout<<"프로그램 종료.\n";

  return 0;
}