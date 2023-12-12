// error1.cpp -- abort() 함수를 사용한다
#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main(void)
{
  double x, y, z;

  std::cout<<"두 수를 입력하십시오 : ";
  while (std::cin>>x>>y)
    {
      z = hmean(x, y);
      std::cout<<x<<", "<<y<<"의 조화평균은 "
        <<z<<"입니다.\n";
      std::cout<<"다른 수를 입력하십시오(끝내려면 q) : ";
    }
  std::cout<<"프로그램을 종료합니다.\n";

  return 0;
}

double hmean(double a, double b)
{
  if (a == -b)
  {
    std::cout<<"매개변수들을 hmean()에 전달할 수 없습니다.\n";
    std::abort();
  }
  
  return 2.0 * a * b / (a + b);
}
