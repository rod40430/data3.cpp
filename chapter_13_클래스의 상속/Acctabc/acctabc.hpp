// acctabc.hpp -- 은행 당좌 클래스
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

// 추상화 기초 클래스
class AcctABC
{
private:
  std::string fullName;
  long acctNum;
  double balance;
protected:
  struct Formatting
  {
    std::ios_base::fmtflags flag;
    std::streamsize pr;
  };
  const std::string & FullName(void) const {return fullName;}
  long AcctNum(void) const {return acctNum;}
  Formatting SetFormat(void) const;
  void Restore(Formatting & f) const;
public:
  AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
  void Deposit(double amt);
  virtual void Withdraw(double amt) = 0;  // 순수 가상 함수
  double Balance(void) const {return balance;}
  virtual void ViewAcct(void) const = 0;
  virtual ~AcctABC(void) {}
};

// Brass Account Class
class Brass : public AcctABC
{
public:
  Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0)
  : AcctABC(s, an, bal) {}
  virtual void Withdraw(double amt);
  virtual void ViewAcct(void) const;
  virtual ~Brass(void) {}
};

// Brass Plus Account Class
class BrassPlus : public AcctABC
{
private:
  double maxLoan;
  double rate;
  double owesBank;
public:
  BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0,
            double ml = 500, double r = 0.1);
  BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
  virtual void Withdraw(double amt);
  virtual void ViewAcct(void) const;
  void ResetMax(double m) {maxLoan = m;}
  void ResetRate(double r) {rate = r;}
  void ResetOwes(void) {owesBank = 0;}
};

#endif
