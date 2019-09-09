#pragma once

#include "date.h"
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

class Database
{
public:
    Database(){};
    void Add (const Date& date, const string& event);
    void Print(ostream& out) const;
    string Last (const Date& date) const;

    template <typename f>
    int RemoveIf(f predicate)
    {
        int count = 0;
        vector<pair<Date, string>> events_for_delete;
        vector<Date> dates_for_delete;
        for (auto i : events)
        {
            for (auto event : i.second.first)
            {
                if (predicate(i.first, event))
                {
                    events_for_delete.push_back(make_pair(i.first, event));
                    ++count;
                }
            }
        }
        for (auto i : events_for_delete)
        {
            events[i.first].first.erase(i.second);
            events[i.first].second.erase(remove(events[i.first].second.begin(), events[i.first].second.end(), i.second), events[i.first].second.end());
            if (events[i.first].first.empty())
                dates_for_delete.push_back(i.first);
        }
        for (auto item : dates_for_delete)
            events.erase(item);
        return count;
    }

    template <typename f>
    vector<string> FindIf(f predicate) const
    {
        vector<string> result;
        stringstream ss;
        for (const auto& i : events)
        {
            for (const auto& event : i.second.second)
            {
                if (predicate(i.first, event))
                {
                    ss << i.first << " " << event;
                    result.push_back(ss.str());
                    ss.str("");
                }
            }
        }
        return result;
    }

private:
    map<Date, pair<set<string>, vector<string>>> events;
};

