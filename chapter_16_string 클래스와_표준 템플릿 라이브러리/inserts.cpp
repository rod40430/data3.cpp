// inserts.cpp -- copy()와 삽입 이터레이터들을 사용한다
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

void output(const std::string & s)
{
  std::cout<<s<<' ';
}

int main(void)
{
  using namespace std;
  string s1[4] = {"fine", "fish", "fashion", "fate"};
  string s2[2] = {"busy", "bats"};
  string s3[2] = {"silly", "singers"};
  vector<string> words(4);

  copy(s1, s1 + 4, words.begin());
  for_each(words.begin(), words.end(), output);
  cout<<endl;

  // 익명의 back_insert_iterator 객체를 생성한다
  copy(s2, s2 + 2, back_inserter<vector<string>>(words));
  for_each(words.begin(), words.end(), output);
  cout<<endl;

  // 역명의 insert_iterator 객체를 생성한다
  copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
  for_each(words.begin(), words.end(), output);
  cout<<endl;

  return 0;
}