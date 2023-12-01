// worker_0.hpp -- 작업 클래스
#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker  // 추상화 기초 클래스
{
private:
  std::string fullname;
  long id;
public:
// 생성자 및 파괴자
  Worker(void) : fullname("no name"), id(0L) {}
  Worker(const std::string & s, long n)
    : fullname(s), id(n) {}
  virtual ~Worker(void) = 0;
// 멤버 함수
  virtual void Set(void);
  virtual void Show(void) const;
};

class Waiter : public Worker
{
private:
  int panache;
public:
// 생성자
  Waiter(void) : Worker(), panache(0) {}
  Waiter(const std::string & s, long n, int p = 0)
    : Worker(s, n), panache(p) {}
  Waiter(const Worker & wk, int p = 0)
    : Worker(wk), panache(p) {}
// 멤버 함수
  void Set(void);
  void Show(void) const;
};

class Singer : public Worker
{
protected:
  enum {other, alto, contralto, soprano, bass, baritone, tenor};
  enum {Vtypes = 7};
private:
  static char * pv[Vtypes];
  int voice;
public:
// 생성자
  Singer(void) : Worker(), voice(other) {}
  Singer(const std::string s, long n, int v = other)
    : Worker(s, n), voice(v) {}
  Singer(const Worker & wk, int v = other)
    : Worker(wk), voice(v) {}
// 멤버함수
  void Set(void);
  void Show(void) const;
};

#endif