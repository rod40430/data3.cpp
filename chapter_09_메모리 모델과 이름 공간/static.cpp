// static.cpp -- 정적 지역 변수 사용하기
#include <iostream>

using namespace std;

// 상수
const int ArSize = 10;

// 함수 원형
void strcount(const char * str);


int main(void)
{ 
  char input[ArSize];
  char next;

  cout<<"영문으로 한 행을 입력하십시오 : \n";
  cin.get(input, ArSize);

  while (cin)
    {
      cin.get(next);
      while (next != '\n')  // 입력한 문자열이 배열의 크기를 초과한다
        cin.get(next);  // 나머지를 삭제한다
      strcount(input);
      cout<<"다음 행을 입력하십시오 (끝내려면 빈 행을 입력) : \n";
      cin.get(input, ArSize);
    }
  cout<<"프로그램을 종료합니다.\n";
  
  return 0;
}

void strcount(const char * str)
{
  static int total = 0;  // 정적 지역 변수
  int count = 0;         // 자동 지역 변수

  cout<<"\""<<str<<"\"에는";

  while (*str++)  // 문자열을 끝까지 카운트한다
    count++;

  total += count;

  cout<<count<<"개의 문자가 있습니다.\n";
  cout<<"지금까지 총 "<<total<<"개의 문자를 입력하셨습니다.\n";
}