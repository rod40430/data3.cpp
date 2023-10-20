// stock10.cpp -- 생성자와 파괴자가 추가된 stock 클래스 구현
#include <iostream>
#include "stock10.hpp"

// 생성자들 (메세지를 출려하는 버전)
stock::stock(void)  // 디폴트 생성자
{
  std::cout<<"디폴트 생성자가 호출되었습니다.\n";
  company = "no-name";
  shares = 0;
  shars_val = 0.0;
  total_val = 0.0;
}

stock::stock(const std::string & co, long n, double pr)
  : company(co), shars_val(pr)
{
  std::cout<<co<<"를 사용하는 생성자가 호출되었습니다.\n";
  if (n < 0)
  {
    std::cout<<"주식 수는 음수가 될 수 없으므로, "
      <<company<<" shares를 0으로 설정합니다.\n";
    shares = 0;
  }
  else
    shares = n;
  
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

  // set format to #.###
  ios_base::fmtflags orig =
    cout.setf(ios_base::fixed, ios_base::floatfield);
  streamsize prec = cout.precision(3);

  cout<<"회사명 : "<<company<<endl;
  cout<<"주식 수 : "<<shares<<endl;
  cout<<"주가 : $"<<shars_val<<endl;
  // set format to #.###
  cout.precision(2);
  cout<<"주식 총 가치 $: "<<total_val<<endl<<endl;

  // 원본 포맷을 저장한다
  cout.setf(orig, ios_base::floatfield);
  cout.precision(prec);
}

// 클래스 파괴자
stock::~stock(void)  // 메세지를 출력하는 클래스 파괴자
{
  std::cout<<"안녕, "<<company<<"!\n";
}
