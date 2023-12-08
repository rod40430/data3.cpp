// tv.cpp -- Tv 클래스를 위한 메서드들 (Remote 메서드들은 인라인으로 사용)
#include <iostream>
#include "tv.hpp"

bool Tv::volup(void)
{
  if (volume < MaxVal)
  {
    volume++;
    return true;
  }
  else
    return false;
}

bool Tv::voldown(void)
{
  if (volume > MinVal)
  {
    volume--;
    return true;
  }
  else
    return false;
}

void Tv::chanup(void)
{
  if (channel < maxchannel)
    channel++;
  else
    channel = 1;
}

void Tv::chandown(void)
{
  if (channel > 1)
    channel--;
  else
    channel = maxchannel;
}

void Tv::setings(void) const
{
  using std::cout;
  using std::endl;
  cout<<"TV = "<<(state == Off ? "OFF" : "ON")<<endl;
  if (state == On)
  {
    cout<<"볼륨 = "<<volume<<endl;
    cout<<"채널 = "<<channel<<endl;
    cout<<"모드 = "
        <<(mode == Antenna ? "지상파 방송" : "케이블 방송")<<endl;
    cout<<"입력 = "<<(input == TV ? "TV" : "DVD")<<endl;
  }
}