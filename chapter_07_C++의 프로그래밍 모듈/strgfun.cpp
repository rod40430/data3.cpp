// strgfun.cpp -- 문자열 매개변수와 함수
#include <iostream>

using namespace std;

unsigned c_in_str(const char * str, char ch);

int main(void)
{
  char mmm[15] = "minimum";  // 배열에 들어 있는 문자열;
  // 배열을 초기화할 수 있다

  char * wail = "ululate";  // wail은 문자열을 지시한다

  unsigned int ms = c_in_str(mmm, 'm');
  unsigned int us = c_in_str(wail, 'u');

  cout<<mmm<<"에는 m이 "<<ms<<"개 들어 있습니다.\n";
  cout<<wail<<"에는 u이 "<<us<<"개 들어 있습니다.\n";
  
  return 0;
}

// 이 함수는 str 문자열에 들어 있는
// ch 문자의 개수를 카운트한다
unsigned c_in_str(const char * str, char ch)
{
  int count = 0;

  while (*str)
    {
      if (*str == ch)
        ++count;
      str++;  // 포인터를 다음 문자로 이동한다
    }

  return count;
}