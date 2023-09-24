// arrstruc.cpp -- 구조체의 배열
#include <iostream>

using namespace std;

typedef struct inflatable
{
  double price;
  float volume;
  char name[20];
}table;

int main(void)
{
  table guests[2] = 
  {
    {21.99, 0.5, "Bambi"},
    {565.99, 2000, "godzilla"}
  };

  cout<<guests[0].name<<"와 "<<guests[1].name
    <<"의 부피를 합하면\n"
    <<guests[0].volume + guests[1].volume
    <<" 세제곱피트입니다.\n";
  
  return 0;
}