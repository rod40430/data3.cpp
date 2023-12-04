// stacktem.cpp -- 포인터들의 스택을 테스트한다
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stacktp.hpp"

namespace 
{
  const int NUM = 10;
}

int main(void)
{
  std::srand(std::time(0));  //  난수 발생기에 씨를 뿌린다
  std::cout<<"스택의 크기를 입력하십시오 : ";
  int stacksize;
  std::cin>>stacksize;

  // stacksize 크기의 빈 스택을 생성한다
  Stack<const char *>st(stacksize);

  // in basket
  const char * in[NUM] =
  {
    "1 : 노미호", "2 : 주리혜",
    "3 : 이몽룡", "4 : 성춘향",
    "5 : 이수일", "6 : 심순애",
    "7 : 박문수", "8 : 홍길동",
    "9 : 김두한", "10: 하야시",
  };

  // out basket
  const char * out[NUM];

  int processed = 0;
  int nextin = 0;

  while (processed < NUM)
    {
      if (st.isempty())
        st.push(in[nextin++]);
      else if (st.isfull())
        st.pop(out[processed++]);
      else if (std::rand() % 2 && nextin < NUM)  // 확률 50%
        st.push(in[nextin++]);
      else
        st.pop(out[processed++]);
    }

  for (int i = 0; i < NUM; ++i)
    std::cout<<out[i]<<std::endl;

  std::cout<<"프로그램을 종료합니다.\n";

  return 0;
}