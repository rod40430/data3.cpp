// usestock0.cpp -- 고객 프로그램
// stock.00.cpp와 컴파일한다
#include <iostream>
#include "stock00.hpp"

int main(void)
{
  stock fluffy_the_cat;
  fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
  fluffy_the_cat.show();
  fluffy_the_cat.buy(15, 18.125);
  fluffy_the_cat.show();
  fluffy_the_cat.sell(400, 20.00);
  fluffy_the_cat.show();
  fluffy_the_cat.buy(30000, 40.125);
  fluffy_the_cat.show();
  fluffy_the_cat.sell(30000, 0.125);
  fluffy_the_cat.show();

  return 0;
}