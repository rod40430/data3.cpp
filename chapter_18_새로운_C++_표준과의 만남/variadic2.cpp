// variadic2.cpp -- variadic1의 개선
#include <iostream>
#include <string>
// 매개변수가 0인 경우 정의
void Show_list()
{
  std::cout<<"매개변수가 없습니다.\n";
}

// 매개변수가 1개인 경우 정의
template<typename T>
void Show_list(const T & value)
{
  std::cout<<value<<'\n';
}

// 매개변수가 2개 이상인 경우 정의
template<typename T, typename... Args>
void Show_list(const T & value, const Args & ... args)
{
  std::cout<<value<<", ";
  Show_list(args...);
}

int main(void)
{
  int n = 14;
  double x = 2.71828;
  std::string mr = "Mr. string objects!";
  Show_list(n, x);
  Show_list(x*x, '!', 7, mr);

  return 0;
}