// usealgo.cpp -- 몇 가지 STL 요소들을 사용한다
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

char toLower(char ch) {return tolower(ch);}
string & ToLower(string & st);

int main(void)
{
  vector<string> words;
  cout<<"단어들을 입력하십시오(끝내려면 quit) : \n";
  string input;
  while (cin>>input && input != "quit")
    words.push_back(input);

  cout<<"다음과 같은 단어들을 입력하셨습니다.\n";
  for (auto x : words)
    cout<<x<<' ';
  cout<<endl;

  // 단어들을 소문자로 변환하여 집합에 넣는다
  set<string> wordset;
  transform(words.begin(), words.end(),
    insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
  
  cout<<"\n단어들의 알파뱃순 리스트 : \n";
  for (auto x : wordset)
    cout<<x<<' ';
  cout<<endl;

  // 단어와 빈도를 맵에 넣는다
  map<string, int> wordmap;
  set<string>::iterator si;

  for (si = wordset.begin(); si != wordset.end(); ++si)
    wordmap[*si] = count(words.begin(), words.end(), *si);

  // 맵의 내용을 출력한다
  for (auto x : wordmap)
    cout<<x.first<<' '<<x.second<<endl;

  return 0;
}

string & ToLower(string & st)
{
  transform(st.begin(), st.end(), st.begin(), toLower);
  return st;
}