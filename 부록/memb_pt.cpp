// memb_pt.cpp -- 클래스 멤버들을 지시하는 멤버 내용 참조 포인터
#include <iostream>
using namespace std;

class Example
{
private:
  int feet;
  int inches;
public:
  Example();
  Example(int ft);
  ~Example();
  void Show_in() const;
  void Show_ft() const;
  void use_ptr() const;
};

Example::Example()
{
  feet = 0;
  inches = 0;
}

Example::Example(int ft)
{
  feet = ft;
  inches = 12 * feet;
}

Example::~Example()
{
  
}

void Example::Show_in() const
{
  cout<<inches<<"인치\n";
}

void Example::Show_ft() const
{
  cout<<feet<<"피트\n";
}

void Example::use_ptr() const
{
  Example yard(3);
  int Example::*pt;
  pt = &Example::inches;
  cout<<"pt를 &Example::inches로 설정 : \n";
  cout<<"this->*pt : "<<this->*pt<<endl;
  cout<<"yard.*pt : "<<yard.*pt<<endl;

  pt = &Example::feet;
  cout<<"pt를 &Example::feet 설정 : \n";
  cout<<"this->*pt : "<<this->*pt<<endl;
  cout<<"yard.*pt : "<<yard.*pt<<endl;

  void (Example::*pf)() const;
  pf = &Example::Show_in;
  cout<<"pf를 &Example::Show_in로 설정 : \n";
  cout<<"(this->*pf)()를 사용 : ";
  (this->*pf)();
  cout<<"(yard.*pf)()를 사용 : ";
  (yard.*pf)();
}

int main(void)
{
  Example car(15);
  Example van(20);
  Example garage;

  cout<<"car.use_ptr()로 출력 : \n";
  car.use_ptr();
  cout<<"\nvan.use_ptr()로 출력 : \n";
  van.use_ptr();

  return 0;
}
