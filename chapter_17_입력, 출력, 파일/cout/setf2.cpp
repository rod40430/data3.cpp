// setf2.cpp -- setf()에 2개의 매개변수를 사용하여 출력 형식을 설정
#include <iostream>
#include <cmath>

int main(void)
{
  using namespace std;
  // 왼쪽 정렬 사용, 플러스 부호를 출력한다
  // 정밀도 3, 뒤에 붙는 0들을 출력한다
  cout.setf(ios_base::left, ios_base::adjustfield);
  cout.setf(ios_base::showpos);
  cout.setf(ios_base::showpoint);
  cout.precision(3);
  // 과학적 E 표기 사용, 이전의 출력 형식을 저장한다
  ios_base::fmtflags old = cout.setf(ios_base::scientific,
    ios_base::floatfield);
  cout<<"왼쪽 정렬 : \n";
  long n;
  for (n = 1; n <= 41; n += 10)
    {
      cout.width(4);
      cout<<n<<'|';
      cout.width(12);
      cout<<sqrt(double(n))<<"!\n";
    }

  // 내부(internal) 정렬로 변경한다
  cout.setf(ios_base::internal, ios_base::adjustfield);
  // 디폴트 부동 소수점 표기를 복원한다
  cout.setf(old, ios_base::floatfield);

  cout<<"내부(internal) 정렬 : \n";
  for (n = 1; n <= 41; n += 10)
    {
      cout.width(4);
      cout<<n<<'|';
      cout.width(12);
      cout<<sqrt(double(n))<<"!\n";
    }

  // 오른쪽 정렬 사용, 고정 소수점 표기로 출력한다
  cout.setf(ios_base::right, ios_base::adjustfield);
  cout.setf(ios_base::fixed, ios_base::floatfield);
  cout<<"오른쪽 정렬 : \n";
  for (n = 1; n <= 41; n += 10)
    {
      cout.width(4);
      cout<<n<<'|';
      cout.width(12);
      cout<<sqrt(double(n))<<"|\n";
    }

  return 0;
}