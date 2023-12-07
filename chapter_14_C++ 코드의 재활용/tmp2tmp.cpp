// tmp2tmp.cpp -- 하나의 템플릿 클래스에 대한 템플릿 프렌드들
#include <iostream>

using std::cout;
using std::endl;

// 템플릿 원형
template <typename T>
void counts(void);
template <typename T>
void report(T &);

// 템플릿 클래스
template <typename TT>
class HasFriend
{
private:
  TT item;
  static int ct;
public:
// 생성자
  HasFriend(const TT & i) : item(i) {ct++;}
// 파괴자
  ~HasFriend(void) {ct--;}
// 프렌드 함수
  friend void counts<TT>(void);  // count<TT>를 사용해도된다
  friend void report<HasFriend <TT>>(HasFriend<TT> &);  // 또는 report<>를 사용해도된다
};

template <typename T>
int HasFriend<T>::ct = 0;

// 템플릿 프렌드 함수들의 정의
template <typename T>
void counts(void)
{
  cout<<"템플릿 크기 : "<<sizeof(HasFriend<T>)<<", ";
  cout<<"템플릿 counts() : "<<HasFriend<T>::ct<<endl;
}

template <typename T>
void report(T & hf)
{
  cout<<hf.item<<endl;
}

int main(void)
{
  counts<int>();
  HasFriend<int> hfi1(10);
  HasFriend<int> hfi2(20);
  HasFriend<double> hfdb(10.5);

  report(hfi1);
  report(hfi2);
  report(hfdb);
  cout<<"counts<int>() 출력 : \n";
  counts<int>();
  cout<<"counts<double>() : 출력 : \n";
  counts<double>();

  return 0;
}