// stock20.cpp -- 개정된 헤더 파일
#ifndef STOCK20_H_
#define STOCK20_H_

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
  void show(void) const;

  const stock & topval(const stock & s) const;

  ~stock();  // 파괴자
};

#endif