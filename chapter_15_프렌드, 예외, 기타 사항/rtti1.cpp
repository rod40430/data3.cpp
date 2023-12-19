// rtti1.cpp -- RTTI dynamic_cast 연산자를 사용한다
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

class Grand
{
private:
  int hold;
public:
  Grand(int h = 0) : hold(h) {}
  virtual void Speak(void) const {cout<<"Grand 클래스\n";}
  virtual int Value(void) const {return hold;}
};

class Superb : public Grand
{
public:
  Superb(int h = 0) : Grand(h) {}
  virtual void Speak(void) const {cout<<"Superb 클래스\n";}
  virtual void Say(void) const
  {
    cout<<"내가 가지고 있는 Superb 값은 "<<Value()<<"이다.\n";
  }
};

class Magnificent : public Superb
{
private:
  char ch;
public:
  Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
  virtual void Speak(void) const {cout<<"Magnificent 클래스\n";}
  virtual void Say(void) const
  {
    cout<<"내가 가지고 있는 문자는 "<<ch<<"이고, 점수는 "
    <<Value()<<"이다";
  }
};

Grand * GetOne(void);

int main(void)
{
  std::srand(std::time(0));
  Grand * pg;
  Superb * ps;

  for (int i = 0; i < 5; i++)
    {
      pg = GetOne();
      pg->Speak();
      if (ps == dynamic_cast<Superb *>(pg))
        ps->Say();
    }

  return 0;
}

Grand * GetOne(void)
{
  Grand * p;
  switch (std::rand() % 3)
    {
      case 0: p = new Grand(std::rand() % 100);
        break;
      case 1: p = new Superb(std::rand() % 100);
        break;
      case 2: p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
        break;
      default :
        break;
    }
  return p;
}