// sales.hpp -- 예외와 상속
#ifndef SALES_H_
#define SALES_H_
#include <iostream>
#include <string>

class Sales
{
protected:
  enum {MONTHS = 12};
public:
  class bad_index : public std::logic_error
  {
  private:
    int bi;
  public:
    explicit bad_index(int ix,
      const std::string & s = "Sales 객체에서 인덱스 에러\n");
    int bi_val(void) const {return bi;}
    virtual ~bad_index(void) throw() = 0;
  };
  explicit Sales(int yy = 0);
  Sales(int yy, const double * gr, int n);
  virtual ~Sales(void) throw() =0;
  int Year(void) const {return year;}
  virtual double operator[](int i) const;
  virtual double & operator[](int i);
private:
  double gross[MONTHS];
  int year;
};

class LabeledSales : public Sales
{
public:
  class nbad_index : public Sales::bad_index
  {
  private:
    std::string lb1;
  public:
    nbad_index(const std::string & lb, int ix,
      const std::string & s = "LabeledSales 객체에서 인덱스 에러\n");
    const std::string & label_val(void) const {return lb1;}
    virtual ~nbad_index(void) throw() = 0;
  };
  explicit LabeledSales(const std::string & lb = "없음", int yy = 0);
  LabeledSales(const std::string & lb, int yy, const double * gr, int n);
  virtual ~LabeledSales(void) = 0;
  const std::string & Label(void) const {return label;}
  virtual double operator[](int i) const;
  virtual double & operator[](int i);
private:
  std::string label;
};

#endif
