// strctfun.cpp -- 구조체 매개변수를 사용하는 함수
#include <iostream>
#include <cmath>

using namespace std;

// 구조체 선언
typedef struct
{
  double distance;  // 원점으로부터의 거리
  double angle;     // 수평축으로부터의 각도
}polar;

typedef struct
{
  double x;  // 원점으로부터의 수평 거리
  double y;  // 원점으로부터의 수직 거리
}rect;

// 함수 원형
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main(void)
{
  rect rplace;
  polar pplace;

  cout<<"x값과 y값을 입력하십시오 : ";
  while (cin>>rplace.x>>rplace.y)
    {
      pplace = rect_to_polar(rplace);
      show_polar(pplace);
      cout<<"x값과 y값을 입력하십시오 (끝내려면 q를 입력) : ";
    }

  cout<<"프로그램을 종료합니다.\n";
  
  return 0;
}

// 직각 좌표를 극 좌표로 변환한다
polar rect_to_polar(rect xypos)
{
  polar answer;

  answer.distance = 
    sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
  answer.angle = atan2(xypos.y, xypos.x);

  return answer;
}

// 라디안 단위를 도 단위로 변환하여 극 좌표를 출력한다
void show_polar(polar dapos)
{
  const double Rad_to_deg = 57.29577951;

  cout<<"거리 = "<<dapos.distance;
  cout<<", 각도 = "<<dapos.angle * Rad_to_deg;
  cout<<"도\n";
}