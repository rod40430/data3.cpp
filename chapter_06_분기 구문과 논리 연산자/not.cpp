// not.cpp -- not 연산자
#include <iostream>
#include <climits>

using namespace std;

bool is_int(double);

int main(void)
{
  double num;

  cout<<"정수 값을 하나 입력하십시오 : ";
  cin>>num;

  while (!is_int(num))                      // num이 int형에 대입할 수 없는 값이면 게속
    {
      cout<<"int형에 대입할 수 없는 값입니다. 다시 입력하십시오 : ";
      cin>>num;
    }
  int val = int (num);          // 데이터 변환
  cout<<"당신이 입력한 정수는 "<<val<<"입니다.\n";
  
  return 0;
}

bool is_int(double x)
{
  if (x <= INT_MAX && x >= INT_MIN)
    return true;
  else
    return false;
}