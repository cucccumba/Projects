#pragma once

#include "date.h"
#include <string>
#include <memory>
enum class Comparison
{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation
{
    Or,
    And
};

class Node
{
public:
    virtual bool Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode: public Node
{
public:
    bool Evaluate(const Date &date, const string &event) override;
};

class DateComparisonNode : public Node
{
public:
    DateComparisonNode(Comparison cmp, Date dt): Comp(cmp), data(dt){}
    bool Evaluate(const Date &date, const string &event) override;
    Comparison Comp;
    Date data;

};

class EventComparisonNode : public Node
{
public:
    EventComparisonNode(Comparison cmp, string str): Comp(cmp), Event(str){}
    bool Evaluate(const Date &date, const string &event) override;
    Comparison Comp;
    string Event;
};

class LogicalOperationNode: public Node
{
public:
    LogicalOperationNode(LogicalOperation lo, shared_ptr<Node> nd1, shared_ptr<Node> nd2): operation(lo), left(nd1), right(nd2){}
    bool Evaluate(const Date &date, const string &event) override;
private:
    LogicalOperation operation;
    shared_ptr<Node> left;
    shared_ptr<Node>  right;
};