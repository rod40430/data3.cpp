// jump.cpp -- continue와 break
#include <iostream>

using namespace std;

const int ArSize = 80;

int main(void)
{
  char line[ArSize];
  int spaces = 0;

  cout<<"한 행의 텍스트를 입력하십시오 : \n";
  cin.get(line, ArSize);
  cout<<"전체 텍스트 : \n"<<line<<endl;
  cout<<"첫 마침표까지의 텍스트 : \n";

  for (int i = 0; line[i] != '\0'; ++i)
    {
      cout<<line[i];                        // 문자를 에코한다

      if (line[i] == '.')                   // 문자가 마치표이면 탈출한다
        break;
      if (line[i] != ' ')                   // 루프의 나머지를 무시한다
        continue;
      ++spaces;                             // 문자가 빈칸일 경우에만 수행된다
    }

  cout<<"\n빈칸 문자는 "<<spaces<<"개입니다.\n";
  cout<<"종료.\n";
  
  return 0;
}