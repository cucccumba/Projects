#pragma once

#include <sstream>

using namespace std;
class Date
{
public:
    Date(){};
    Date(const int& y, const int& m, const int& d);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    int year;
    int month;
    int day;
};

ostream& operator << (ostream& out, const Date& date);
bool operator < (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs,  const Date& rhs);
bool operator >= (const Date& lhs,  const Date& rhs);
bool operator <= (const Date& lhs,  const Date& rhs);
Date ParseDate(istream& s);
