// usetime3.cpp -- TIme 클래스의 네 번째 드래프트 버전을 사용한다
// usetime3.cpp 와 mytime3.cpp를 함께 컴파일한다
#include <iostream>
#include "mytime3.hpp"

int main(void)
{
  using std::cout;
  using std::endl;

  Time aida(3, 35);
  Time tosca(2, 48);
  Time temp;

  cout<<"Aida와 Tosca : \n";
  cout<<aida<<"; "<<tosca<<endl;
  temp = aida + tosca;  // operator+()
  cout<<"Aida + Tosca : "<<temp<<endl;
  temp = aida * 1.17;  // 멤버 operator*()
  cout<<"Aida * 1.17 : "<<temp<<endl;
  cout<<"10 * Tosca : "<<10 * tosca<<endl;
  
  return 0;
}