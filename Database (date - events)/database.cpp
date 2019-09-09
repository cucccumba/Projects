#include "database.h"

void Database::Add (const Date& date, const string& event)
{
    if (!events[date].first.count(event))
    {
        events[date].first.insert(event);
        events[date].second.push_back(event);
    }
}

void Database::Print(ostream &out) const
{
    for (const auto& event : events)
    {
        for (const auto& ev : event.second.second)
        {
            out << event.first << " " << ev << endl;
        }
    }
}

string Database::Last(const Date &date) const
{
    stringstream res;
    if (events.empty())
        throw invalid_argument("");
    auto it = events.upper_bound(date);
    if (it == events.begin())
    {
        if ((*it).first == date)
        {
            res << date << " " << events.at(date).second.back();
            return res.str();
        }
        else
            throw invalid_argument("");
    }
    else
    {
        --it;
        res << (*it).first << " " << (*it).second.second.back();
        return res.str();
    }
}
