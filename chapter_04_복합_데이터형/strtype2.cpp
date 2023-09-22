// strtype2.cpp -- 대입, 추가, 첨부
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
  string s1 = "penguin";
  string s2, s3;

  cout<<"string 객체를 string 객체에 대입할 수 있다 : s2 = s1\n";
  s2 = s1;
  cout<<"s1 : "<<s1<<", s2 : "<<s2<<endl;
  cout<<"s2 = \"buzzard\"\n";
  s2 = "buzzard";
  cout<<"s2 : "<<s2<<endl;
  cout<<"string 객체들을 결합할 수 있다 : s3 = s1 + s2\n";
  s3 = s1 + s2;
  cout<<"s3 : "<<s3<<endl;
  cout<<"string 객체들을 추가할 수 있다.\n";
  s1 += s2;
  cout<<"s1 += s2 --> s1 = "<<s1<<endl;
  s2 += " for a day";
  cout<<"s2 += \"for a day\" --> s2 = "<<s2<<endl;

  return 0;
}