// recur.cpp -- 함수의 재귀 호출
#include <iostream>

using namespace std;

void countdown(int n);

int main(void)
{
  countdown(10);  // 재귀함수를 호출한다
  
  return 0;
}

void countdown(int n)
{
  cout<<"카운트 다운 ..."<<n<<endl;
  if (n > 0)
    countdown(n - 1);  // 함수가 자기 자신을 호출한다
  cout<<n<<" : kaboom!\n";
}