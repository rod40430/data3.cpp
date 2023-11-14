// tabtenn1.cpp -- 간단한 기초 클래스 메서드들
#include "tabtenn1.hpp"
#include <iostream>
using std::string;

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht)
: firstname(fn), lastname(ln), hasTable(ht) {;}

void TableTennisPlayer::Name() const
{
  std::cout<<lastname<<", "<<firstname;
}

// RatedPlayer 메서드
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
            const string & ln, bool ht) 
: TableTennisPlayer(fn, ln, ht)
{
  rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
: TableTennisPlayer(tp), rating(r) {}