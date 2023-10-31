// stone1.cpp -- 사용자 정의 변환 함수
// stonewt1.cpp와 함계 컴파일한다
#include <iostream>
#include "stonewt1.hpp"

void display(const Stonewt & st, int n);

int main(void)
{
  using std::cout;

  Stonewt poppins(9, 2.8);  // 9스톤, 2.8 파운드
  double p_wt = poppins;  // 암시적 변환

  cout<<"double형으로 변환 -> "
      <<"poppins : "<<p_wt<<"파운드\n"
      <<"int형으로 변환 -> "
      <<"poppins : "<<int(poppins)<<"파운드\n";

  return 0;
}