// if.cpp --  if 구문
#include <iostream>

using namespace std;

int main(void)
{
  int spaces = 0;
  int total = 0;
  char ch;

  cin.get(ch);

  while(ch != '.')            // 문장의 끝 (마침표)에서 루프 종료
    {
      if (ch == ' ')          // ch가 빈칸인지 검사
        ++spaces;             // ch가 빈칸인일 때에만 수행
      ++total;                // 빈칸이든 아니든 매번 수행
      cin.get(ch);
    }

  cout<<"이 문장의 총 문자 수는 : "<<total<<"이고, ";
  cout<<"그 중에서 빈칸은 : "<<spaces<<"개입니다.\n";
  
  return 0;
}
