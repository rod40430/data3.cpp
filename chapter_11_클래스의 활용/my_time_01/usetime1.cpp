// usetime1.cpp -- TIme 클래스의 첫 번째 드래프트 버전을 사용한다
// usetime1.cpp 와 mytime1.cpp를 함께 컴파일한다
#include <iostream>
#include "mytime1.hpp"

int main(void)
{
  using std::cout;
  using std::endl;

  Time planning;
  Time coding(2, 40);
  Time fixing(5, 55);
  Time total;
  
  cout<<"planning time = ";
  planning.Show();
  cout<<endl;
  
  cout<<"coding time = ";
  coding.Show();
  cout<<endl;

  cout<<"fixing time = ";
  fixing.Show();
  cout<<endl;

  total = coding + fixing;
  // 연산자 표기
  cout<<"coding + fixing = ";
  total.Show();
  cout<<endl;

  Time morfixing(3, 28);
  cout<<"more fixing time = ";
  morfixing.Show();
  cout<<endl;

  total = morfixing.operator+(total);
  // 함수 표기
  cout<<"morfixing.operator+(total) = ";
  total.Show();
  cout<<endl;
  
  return 0;
}