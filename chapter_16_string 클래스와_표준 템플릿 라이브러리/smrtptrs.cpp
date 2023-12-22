// smrtptrs.cpp -- 세 개의 스마트 포인터들을 사용
// C++11 shared_ptr과 unique_ptr 클래스를 지원해야 함
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
  std::string str;
public:
  Report(const std::string & s) : str(s)
  {
    std::cout<<"객체가 생성되었습니다.\n";
  }
  ~Report(void)
  {
    std::cout<<"객체가 삭제되었습니다.\n";
  }
  void comment(void) const
  {
    std::cout<<str<<"\n";
  }
};

int main(void)
{
  {
    std::auto_ptr<Report> ps (new Report("auto_ptr"));
    ps->comment();  // 멤버 함수를 사용하기 위해 ->를 사용
  }
  {
    std::shared_ptr<Report> ps (new Report("shared_ptr"));
    ps->comment();
  }
  {
    std::unique_ptr<Report> ps (new Report("unique_ptr"));
    ps->comment();
  }

  return 0;
}