// tabtenn0.cpp -- 간단한 기초 클래스 메서드들
#include "tabtenn0.hpp"
#include <iostream>
using std::string;

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht)
: firstname(fn), lastname(ln), hasTable(ht) {;}

void TableTennisPlayer::Name() const
{
  std::cout<<lastname<<", "<<firstname;
}
