// worktest.cpp -- 사원 클래스 계층을 테스트한다
#include "worker_0.hpp"
#include <iostream>

namespace
{
  const int LIM = 4;
}

int main(void)
{
  Waiter bob("홍길동", 314L, 5);
  Singer bev("조수미", 522L, 3);

  Waiter w_temp;
  Singer s_temp;

  Worker * pw[LIM] = {&bob, &bev, &w_temp, &s_temp};

  int i;

  for (i = 2; i < LIM; ++i)
    pw[i]->Set();

  for (i = 0; i < LIM; ++i)
    {
      pw[i]->Show();
      std::cout<<std::endl;
    }

  return 0;
}