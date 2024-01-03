// check_it.cpp -- 적절한 입력인지 확인한다
#include <iostream>

int main(void)
{
  using namespace std;
  cout<<"수를 입력하십시오 : ";

  int sum = 0;
  int input;

  while (cin>>input)
    {
      sum += input;
    }

  cout<<"마지막으로 입력한 값 = "<<input<<endl;
  cout<<"합계 = "<<sum<<endl;

  return 0;
}
