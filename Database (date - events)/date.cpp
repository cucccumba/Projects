#include "date.h"
#include <iomanip>
#include <vector>
#include <string>

Date::Date(const int& y, const int& m, const int& d)
{
    year = y;
    month = m;
    day = d;
}

int Date::GetYear() const
{
    return year;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetDay() const
{
    return day;
}

ostream& operator << (ostream& out, const Date& date)
{
    out << setw(4) << setfill('0') << date.GetYear() << "-" << setw(2) << setfill('0') << date.GetMonth()
    << "-" << setw(2) << setfill('0') << date.GetDay();
    return out;
}

bool operator < (const Date& lhs, const Date& rhs)
{
    vector<int> l = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}, r = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
    return l < r;
}
bool operator > (const Date& lhs, const Date& rhs)
{
    vector<int> l = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}, r = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
    return l > r;
}
bool operator == (const Date& lhs, const Date& rhs)
{
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}
bool operator != (const Date& lhs,  const Date& rhs)
{
    return !(lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}
bool operator <= (const Date& lhs, const Date& rhs)
{
    vector<int> l = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}, r = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
    return l <= r;
}
bool operator >= (const Date& lhs, const Date& rhs)
{
    vector<int> l = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()}, r = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
    return l >= r;
}

Date ParseDate(istream& s)
{
    string str;
    s >> str;
    istringstream date_stream(str);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok)
    {
        throw logic_error("Wrong date format");
    }
    return Date(year, month, day);
}