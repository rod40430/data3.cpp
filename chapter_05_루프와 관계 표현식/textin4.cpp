// textin4.cpp --  cin.get() 으로 문자 읽기
#include <iostream>

using namespace std;

int main(void)
{
  int ch;                             // char형이 아니라 int형이어야 한다
  int count = 0;

  while ((ch = cin.get()) != EOF)         // EOF인지 검사한다 
    {                                     // EOF = -1이다 그래서 int형으로 검사하는것 이다.
      cout.put(char(ch));
      ++count;
    }

  cout<<count<<" 문자를 읽었습니다.\n";
  
  return 0;
}