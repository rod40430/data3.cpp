// modulus.cpp -- % 연산자를 사용하여 파운드를 스톤으로 변환한다
#include <iostream>

using namespace std;

int main(void)
{
  const int Lbs_per_stn = 14;
  int lbs;

  cout<<"당신의 체중을 파운드 단위로 입력하시오 :";
  cin>>lbs;
  int stone = lbs / Lbs_per_stn;  // 몫은 스톤으로
  int pound = lbs % Lbs_per_stn;  // 나머지는 파운드로
  cout<<lbs<<"파운드는 "<<stone
    <<"스톤, "<<pound<<"파운드입니다.\n";

  return 0;
}