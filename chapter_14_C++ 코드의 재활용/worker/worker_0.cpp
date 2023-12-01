// worker_0.cpp -- 작업 클래스 메서드들
#include "worker_0.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Worker 메서드들

// 순수 함수일지라도 가상 파괴자를 구현해야 한다.
Worker::~Worker() {}

void Worker::Set()
{
  cout<<"사원 이름을 입력하십시오 : ";
  getline(cin, fullname);
  cout<<"사원 번호를 입력하십시오 : ";
  cin>>id;

  while (cin.get() != '\n')
    continue;
}

void Worker::Show() const
{
  cout<<"사원 이름 : "<<fullname<<endl;
  cout<<"사원 번호 : "<<id<<endl;
}

// Waiter 메서드들
void Waiter::Set()
{
  Worker::Set();
  cout<<"웨이터 등급을 입력하십시오 : ";
  cin>>panache;

  while (cin.get() != '\n')
    continue;
}

void Waiter::Show() const
{
  cout<<"직종 : 웨이터\n";
  Worker::Show();
  cout<<"웨이터 등급 : "<<panache<<endl;
}

// Singer 메서드들

char* Singer::pv[Singer::Vtypes] = 
{
"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"
};

void Singer::Set()
{
  Worker::Set();
  cout<<"가수의 목소리 유형 번호를 입력하십시오 : \n";
  int i;
  for (i = 0; i < Vtypes; ++i)
    {
      cout<<i<<" : "<<pv[i]<<" ";
      if (i % 4 == 3)
        cout<<endl;
    }
  if (i % 4 != 0)
    cout<<endl;
  while (cin>>voice && (voice < 0 || voice >= Vtypes))
    cout<<"0보다 크거나 같고 "<<Vtypes<<"보다 작은 값을 입력하십시오\n";

  while (cin.get() != '\n')
    continue;
}

void Singer::Show() const
{
  cout<<"직종 : 가수\n";
  Worker::Show();
  cout<<"목소리 유형 : "<<pv[voice]<<endl;
}