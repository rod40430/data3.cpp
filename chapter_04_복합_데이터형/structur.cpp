// structur.cpp -- 간단한 구조체
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
  table guest = 
  {
    29.99,  // price값
    1.88,  // volume 값
    "Glorious Gloria"  // name 값
  };

  table pal =
  {
    32.99,
    3.12,
    "Audacious Arthur"
  };

  cout<<"지금 판매하고 있는 모형풍성은\n"<<guest.name
    <<"와 "<<pal.name<<"입니다.\n";

  cout<<"두 제품을 $"
    <<guest.price + pal.price<<"에 드리겠습니다!\n";
  
  return 0;
}