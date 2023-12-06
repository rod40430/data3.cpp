// frnd2tmp.cpp -- 템플릿이 아닌 프렌드를 가지는 템플릿 클래스
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
  T item;
  static int ct;
public:
// 생성자
  HasFriend(const T & i) : item(i) {ct++;}
// 파괴자
  ~HasFriend(void) {ct--;}
// 프렌드 함수
  friend void counts(void);
  friend void report(HasFriend<T> &);  // 템플릿 매개변수
};

// 각 특수화는 자신만의 static 데이터 멤버를 가진다
template <typename T>
int HasFriend<T>::ct = 0;

// 모든 HasFriend<T> 클래스에 대해 템플릿이 아닌 프렌드
void counts(void)
{
  cout<<"int 카운트 : "<<HasFriend<int>::ct<<", "
      <<"double 카운트 : "<<HasFriend<double>::ct<<endl;
}

// HasFriend<int> 클래스에 대해 템플릿이 아닌 프렌드
void report(HasFriend<int> & hf)
{
  cout<<"HasFriend<int> : "<<hf.item<<endl;
}

// HasFriend<double> 클래스에 대해 템플릿이 아닌 프렌드
void report(HasFriend<double> & hf)
{
  cout<<"HasFriend<double> : "<<hf.item<<endl;
}

int main(void)
{
  cout<<"객체가 선언되지 않았다 : ";
  counts();
  HasFriend<int> hfi1(10);
  cout<<"hfi1 선언 후 : ";
  counts();
  HasFriend<int> hfi2(20);
  cout<<"hfi2 선언 후 : ";
  counts();

  HasFriend<double> hfdb(10.5);
  cout<<"hfdb 선언 후 : ";
  counts();

  report(hfi1);
  report(hfi2);
  report(hfdb);

  return 0;
}