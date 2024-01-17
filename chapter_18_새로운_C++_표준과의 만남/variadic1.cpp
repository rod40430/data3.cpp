// variadic1.cpp -- 매개변수 팩을 언팩하는 재귀 이용
#include <iostream>
#include <string>
// 매개변수가 없을 때 정의 -- 호출 종료
void Show_list3()
{
  std::cout<<"매개변수가 없습니다.\n";
}

// 1개 이상일 때 정의
template<typename T, typename... Args>
void Show_list3(T value, Args... args)
{
  std::cout<<value<<", ";
  Show_list3(args...);
}

int main(void)
{
  int n = 14;
  double x = 2.71828;
  std::string mr = "Mr. string objects!";
  Show_list3(n, x);
  Show_list3(x*x, '!', 7, mr);

  return 0;
}