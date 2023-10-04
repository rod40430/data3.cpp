// cingolf.cpp -- 수가 아닌 입력은 무시한다
#include <iostream>

using namespace std;

const int Max = 5;

int main(void)
{
  int golf[Max];
  cout<<"골프 점수를 입력하십시오.\n";
  cout<<"총 "<<Max<<" 라운드 점수를 입력해야 합니다.\n";
  int i;

  for (i = 0; i < Max; ++i)
    {
      cout<<"round #"<<i + 1<<" : ";
      while (!(cin>>golf[i]))
        {
          cin.clear();  // 입력을 초기화한다
          while (cin.get() != '\n')
            continue;  // 불량 입력을 제거한다
          cout<<"골프 점수를 입력하십시오 : ";
        }
    }

  double total = 0.0;
  for (i = 0; i < Max; ++i)
    total += golf[i];

  cout<<"총 "<<Max<<"라운드의 평균 점수 = "
    <<total / Max<<endl;
  
  return 0;
}