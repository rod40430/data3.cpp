// useless.cpp -- 다른 관점에서 move semantics을 구현한 useless 클래스
#include <iostream>

using namespace std;

// 인터페이스
class Useless
{
private:
  int n;  // 매개변수 수
  char * pc;  // 데이터를 가리키는 포인터
  static int ct;  // 객체 수
  void ShowObject(void) const;
public:
  Useless(void);
  explicit Useless(int k);
  Useless(int k, char ch);
  Useless(const Useless & f);  // 일반적인 복사 생성자
  Useless(Useless && f);  // 이동 생성자
  ~Useless(void);
  Useless operator+(const Useless & f) const;
// 복사와 생성에 연산자 =() 필요
  void ShowData(void) const;
};

// 구현
int Useless::ct = 0;

Useless::Useless(void)
{
  ++ct;
  pc = nullptr;
  cout<<"기본 생성자 호출; 객체 수 : "<<ct<<endl;
  ShowObject();
}

Useless::Useless(int k) : n(k)
{
  ++ct;
  cout<<"int 생성자 호출; 객체 수 : "<<ct<<endl;
  pc = new char[n];
  ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
  ++ct;
  cout<<"int 생성자 호출; 객체 수 : "<<ct<<endl;
  pc = new char[n];
  for (int i = 0; i < n; i++)
    pc[i] = ch;
  ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
  ++ct;
  cout<<"int 복사 const 호출; 객체 수 : "<<ct<<endl;
  pc = new char[n];
  for (int i = 0; i < n; i++)
    pc[i] = f.pc[i];
  ShowObject();
}

Useless::Useless(Useless && f) : n(f.n)
{
  ++ct;
  cout<<"이동 생성자 호출; 객체 수 :"<<ct<<endl;
  pc = f.pc;  // 주소 가로챔
  f.pc = nullptr;  // 이전 객체가 아무것도 변환하지 않도록 함
  f.n = 0;
  ShowObject();
}

Useless::~Useless(void)
{
  cout<<"소멸자 호출; 남은 객체 : "<<--ct<<endl;
  cout<<"삭제된 객체 : \n";
  ShowObject();
  delete []pc;
}

Useless Useless::operator+(const Useless & f) const
{
  cout<<"연산자 +() 진입 \n";
  Useless temp = Useless(n + f.n);
  for (int i = 0; i < n; ++i)
    temp.pc[i] = pc[i];
  for (int i = n; i < temp.n; ++i)
    temp.pc[i] = f.pc[i - n];
  cout<<"임시 객체 : \n";
  cout<<"연산자 : () 나옴\n";
  return temp;
}

void Useless::ShowObject(void) const
{
  cout<<"매개변수 수 : "<<n<<endl;
  cout<<"데이터 주소 : "<<(void *) pc<<endl;
}

void Useless::ShowData(void) const
{
  if (n == 0)
    cout<<"(객체없음)";
  else
    for (int i = 0; i < n; ++i)
      cout<<pc[i];
  cout<<endl;
}

// 애플리케이션
int main(void)
{
  Useless one(10, 'x');
  Useless two = one;  // 복사 생성자 호출
  Useless three(20, 'o');
  Useless four(one + three);  // +() 연산자, 이동 생성자 호출
  cout<<"객체 one : ";
  one.ShowData();
  cout<<"객체 two : ";
  two.ShowData();
  cout<<"객체 three : ";
  three.ShowData();
  cout<<"객체 four : ";
  four.ShowData();

  return 0;
}