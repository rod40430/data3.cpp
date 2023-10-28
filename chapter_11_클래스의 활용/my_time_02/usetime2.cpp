// usetime2.cpp -- TIme 클래스의 세 번째 드래프트 버전을 사용한다
// usetime2.cpp 와 mytime2.cpp를 함께 컴파일한다
#include <iostream>
#include "mytime2.hpp"

int main(void)
{
  using std::cout;
  using std::endl;

  Time weeding(4, 35);
  Time waxing(2, 47);
  Time total;
  Time diff;
  Time adjusted;

  cout<<"weeding Time = ";
  weeding.Show();
  cout<<endl;

  cout<<"waxing Time = ";
  waxing.Show();
  cout<<endl;

  cout<<"total work Time = ";
  total = weeding + waxing;  // operator+() 사용
  total.Show();
  cout<<endl;

  diff = weeding - waxing;  // operator-() 사용
  cout<<"weeding - waxing = ";
  diff.Show();
  cout<<endl;

  adjusted = total * 1.5;  // operator*() 사용
  cout<<"adjusted Time = ";
  adjusted.Show();
  cout<<endl;
  
  return 0;
}