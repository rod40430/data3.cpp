// condit.cpp -- 조건 연산자 (삼항 연산자)
#include <iostream>

using namespace std;

int main(void)
{
  int a, b;
  cout<<"두 개의 정수를 입력하십시오 : ";
  cin>>a>>b;
  cout<<"둘 중에서 더 큰 정수는 ";
  int c = a > b ? a : b;              // a > b이면 c = a, 그렇지 않으면 c = b;
  cout<<c<<" 입니다.\n";
  
  return 0;
}
