// delete.cpp -- delete 연산자 사용
#include <iostream>
#include <cstring>

using namespace std;

char * getname(void);

int main(void)
{
  char * name;

  name = getname();
  cout<<(int *) name<<" : "<<name<<endl;
  delete []name;

  name = getname();
  cout<<(int *) name<<" : "<<name<<endl;
  delete []name;
  
  return 0;
}

char * getname(void)
{
  char temp[80];  // 임시 배열
  cout<<"이름을 입력하십시오 : ";
  cin>>temp;
  char * pn = new char[strlen(temp) + 1];
  strcpy(pn, temp);  // 문자열을 더 작은 공간으로 복사한다

  return pn;  // 함수가 종료될 때 임시 배열인 temp는 소멸한다
}