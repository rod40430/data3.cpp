// stock10.cpp -- 생성자들과 파괴자가 추가된 stock 클래스 선언
#ifndef STOCK10_H_
#define STOCK10_H_

#include <string>

class stock
{
private:
  double shars_val;
  double total_val;
  long shares;
  std::string company;
  void set_tot()  {total_val = shares * shars_val;}

public:
// 두 개의 생성자
  stock();
  stock(const std::string & co, long n = 0, double pr = 0);
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  void show(void);
  ~stock();  // 파괴자
};

#endif