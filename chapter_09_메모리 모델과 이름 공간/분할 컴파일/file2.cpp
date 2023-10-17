// file2.cpp -- file1.cpp에서 호출되는 함수가 들어 있다
#include <cmath>
#include "coordin.hpp"

using namespace std;

// 직각 좌표를 극 좌표로 변환한다
polar rect_to_polar(rect xypos)
{
  polar answer;

  answer.distance =
    sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
  answer.angle = atan2(xypos.y, xypos.x);

  return answer;  // polar형 구조체를 리턴한다
}

// 라디안 단위를 도 단위로 변환하여 극 좌표를 출력한다
void show_polar(polar dapos)
{
  const double Rad_to_deg = 57.29577951;

  cout<<"거리 = "<<dapos.distance;
  cout<<", 각도 = "<<dapos.angle * Rad_to_deg;
  cout<<"도\n";
}