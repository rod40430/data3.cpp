// functor.cpp -- 펑크터를 사용한다
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template <typename T>  // 펑크터 클래스가 operator() ()를 정의한다
class TooBig
{
private:
  T cutoff;
public:
  TooBig(const T & t) : cutoff(t) {}
  bool operator() (const T & v) {return v > cutoff;}
};

void outint(int n) {std::cout<<n<<" ";}

int main(void)
{
  using std::list;
  using std::cout;
  using std::endl;

  TooBig<int> f100(100);  // 제한 = 100
  int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 210};
  list<int> yadayada(vals, vals + 10);
  list<int> etcetera(vals, vals + 10);
  // C++11 은 다음의 코드를 대신 사용할 수 있다
  // list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 210};
  // list<int> etcetera = {50, 100, 90, 180, 60, 210, 415, 88, 188, 210};
  cout<<"원래의 리스트 : \n";
  for_each(yadayada.begin(), yadayada.end(), outint);
  cout<<endl;
  for_each(etcetera.begin(), etcetera.end(), outint);
  cout<<endl;
  yadayada.remove_if(f100);  // 이름이 있는 함수 객체를 사용한다
  etcetera.remove_if(TooBig<int>(200));  // 함수 객체를 생성한다
  cout<<"정비된 리스트 : \n";
  for_each(yadayada.begin(), yadayada.end(), outint);
  cout<<endl;
  for_each(etcetera.begin(), etcetera.end(), outint);
  cout<<endl;

  return 0;
}