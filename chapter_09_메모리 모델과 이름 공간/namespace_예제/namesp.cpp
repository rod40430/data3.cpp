// namesp.cpp -- 이름 공간들
#include <iostream>
#include "namesp.hpp"

namespace pers
{
  using std::cout;
  using std::cin;

  void getPerson(Person & rp)
  {
    cout<<"이름을 입력하십시오 : ";
    cin>>rp.fname;
    cout<<"성씨를 입력하십시오 : ";
    cin>>rp.lname;
  }
  
  void showPerson(const Person & rp)
  {
    cout<<rp.fname<<", "<<rp.lname;
  }
}

namespace debts
{
  void getDebt(Debt & rd)
  {
    getPerson(rd.name);
    cout<<"부채를 입력하십시오 :  ";
    cin>>rd.amount;
  }
  
  void showDebt(const Debt & rd)
  {
    showPerson(rd.name);
    cout<<" : $"<<rd.amount<<std::endl;
  }
  
  double sumDebts(const Debt * ar, int n)
  {
    double total = 0;
    for (int i = 0; i < n; i++)
      total += ar[i].amount;

    return total;
  }
}