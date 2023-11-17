// brass.hpp -- 은행 당좌 클래스
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
// Brass Acount Class
class Brass
{
private:
  std::string fullName;
  long acctNum;
  double balance;
public:
  Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
  void Deposit(double amt);
  virtual void Withdraw(double amt);
  double Balance(void) const;
  virtual void ViewAcct(void) const;
  virtual ~Brass(void) {}
};

// Brass Plus Account Class
class BrassPlus : public Brass
{
private:
  double maxLoan;
  double rate;
  double owesBank;
public:
  BrassPlus(const std::string & s = "Nullbody", long an = -1,
            double bal = 0.0, double m1 = 500, double r = 0.11125);
  BrassPlus(const Brass & ba, double m1 = 500, double r = 0.11125);
  virtual void ViewAcct(void) const;
  virtual void Withdraw(double amt);
  void ResetMax(double m) {maxLoan = m;}
  void ResetPate(double r) {rate = r;}
  void ResetOwes(void) {owesBank = 0;}
};

#endif