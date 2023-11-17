// usebrass2.cpp -- 다형(polymorphism)을 설명하는 예제
// brass.cpp와 함께 컴파일한다
#include <iostream>
#include "brass.hpp"

namespace
{
  const int CLIENTS = 4;
}

int main(void)
{
  using std::cin;
  using std::cout;
  using std::endl;

  Brass * P_clients[CLIENTS];
  std::string temp;
  long tempnum;
  double tempbal;
  char kind;

  for (int i = 0; i < CLIENTS; i++)
    {
      cout<<"고객의 이름을 입력하십시오 : ";
      getline(cin,temp);
      cout<<"고객의 계좌 번호를 입력하십시오 : ";
      cin>>tempnum;
      cout<<"계좌 개설 잔액을 입력하십시오 : $";
      cin>>tempbal;
      cout<<"Brass 게좌는 1, "
          <<"BrassPlus 계좌는 2를 입력하십시오 : ";
      while (cin>>kind && (kind != '1' && kind != '2'))
        cout<<"1 아니면 2, 둘 중 하나를 입력하십시오 : ";
      if (kind == '1')
        P_clients[i] = new Brass(temp, tempnum, tempbal);
      else
      {
        double tmax, trate;
        cout<<"당좌 대월 한도를 입력하십시오 : $";
        cin>>tmax;
        cout<<"당좌 대월 이자율을 소수점 형식으로 "
            <<"입력하십시오 : ";
        cin>>trate;
        P_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
      }
      while (cin.get() != '\n')
        continue;
    }
  cout<<endl;
  for (int i = 0; i < CLIENTS; i++)
    {
      P_clients[i]->ViewAcct();
      cout<<endl;
    }

  for (int i = 0; i < CLIENTS; i++)
    delete P_clients[i];  // 메모리를 해제한다

  cout<<"프로그램을 종료합니다.\n";

  return 0;
}