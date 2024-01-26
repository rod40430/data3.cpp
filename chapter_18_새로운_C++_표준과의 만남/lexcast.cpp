// lexcast.cpp -- string으로 변환하는 간단한 예제
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

int main(void)
{  
  using namespace std;

  cout<<"몸무게를 입력하세요 : ";
  float weight;
  cin>>weight;
  string gain = "10% 증가하면 ";
  string wt = boost::lexical_cast<string>(weight);
  gain = gain + wt + "이 ";  // 문자 연산자+()
  weight = 1.1 * weight;
  gain = gain + boost::lexical_cast<string>(weight) + "이 됩니다.";
  cout<<gain<<endl;

  return 0; 
}
