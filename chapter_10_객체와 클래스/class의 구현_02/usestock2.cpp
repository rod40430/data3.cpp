// usestock2.cpp -- stock 클래스를 사용한다
// stock.20.cpp와 컴파일한다
#include <iostream>
#include "stock20.hpp"

namespace
{
  const int STKS = 4;
}

int main(void)
{
  // 초기화된 객체들의 배열을 생성한다
  stock stocks[STKS] = 
  {
    stock("NanoSmart", 12, 20.0),
    stock("Boffo objects", 200, 2.0),
    stock("Monolithic obelisks", 130, 3.25),
    stock("Fleep Enterpriess", 60, 6.5)
  };

  std::cout<<"보유 주식 리스트 : \n";
  int st;
  for (st = 0; st < STKS; st++)
    stocks[st].show();

  // 첫 번째 원소에 포인터 지점
  const stock * top = stocks;  // &stocks[0]
  for (st = 1; st < STKS; st++)
    top = &(top->topval(*(stocks + st)));

  // 가장 가치 있는 주식의 최고치
  std::cout<<"\n최고 가치의 주식 : \n";
  top->show();

  return 0;
}