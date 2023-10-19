// stock.cpp -- stock 클래스 구현
// version 00
#include <iostream>
#include "stock00.hpp"

void stock::acquire(const std::string & co, long n, double pr)
{
  company = co;
  if (n < 0)
  {
    std::cout<<"주식 수는 음수가 될 수 없으므로, "
      <<company<<" shares를 0으로 설정합니다.\n";
    shares = 0;
  }
  else
    shares = n;
  
  shars_val = pr;
  set_tot();
}

void stock::buy(long num, double price)
{
  if (num < 0)
  {
    std::cout<<"매입 주식 수는 음수가 될 수 없음므로, "
      <<"거래가 취소되었습니다.\n";
    return;
  }
  else
  {
    shares += num;
    shars_val = price;
    set_tot();
  }
}

void stock::sell(long num, double price)
{
  using std::cout;

  if (num < 0)
  {
    cout<<"매도 주식 수는 음수가 될 수 없으므로, "
      <<"거래가 취소되었습니다.\n";
    return;
  }
  else if (num > shares)
  {
    cout<<"보유 주식보다 많은 주식을 매도할 수 없으므로, "
      <<"거래가 취소되었습니다.\n";
    return;
  }
  else
  {
    shares -= num;
    shars_val = price;
    set_tot();
  }
}

void stock::update(double price)
{
  shars_val = price;
  set_tot();
}

void stock::show(void)
{
  using namespace std;

  cout<<"회사명 : "<<company<<endl;
  cout<<"주식 수 : "<<shares<<endl;
  cout<<"주가 : $"<<shars_val<<endl;
  cout<<"주식 총 가치 $: "<<total_val<<endl<<endl;
}