// stock00.cpp -- stock 클래스 인터페이스
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class stock
{
private:
  double shars_val;
  double total_val;
  long shares;
  std::string company;
  void set_tot()  {total_val = shares * shars_val;}  // 클래스 선언 안에 정의를 가지면
                                                     // 인라인 함수가 된다
public:
  void acquire(const std::string & co, long n, double pr);
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  void show(void);
};

#endif