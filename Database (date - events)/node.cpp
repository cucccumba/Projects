#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const string &event)
{
    return true;
}

bool DateComparisonNode::Evaluate(const Date &date, const string &event)
{
    switch(Comp)
    {
        case Comparison::NotEqual:
            return date != data;
        case Comparison::Less:
            return date < data;
        case Comparison::LessOrEqual:
            return date < data || date == data;
        case Comparison::Greater:
            return date > data;
        case Comparison::GreaterOrEqual:
            return date > data || date == data;
        case Comparison::Equal:
            return date == data;
        default: throw invalid_argument("expected comparison");
    }
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event)
{
    switch(Comp)
    {
        case Comparison::NotEqual:
            return event != Event;
        case Comparison::Equal:
            return event == Event;
        case Comparison::Less:
            return event < Event;
        case Comparison::LessOrEqual:
            return event < Event || event == Event;
        case Comparison::Greater:
            return event > Event;
        case Comparison::GreaterOrEqual:
            return event > Event || event == Event;
        default: throw invalid_argument("expected comparison");
    }
}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event)
{
    switch(operation)
    {
        case LogicalOperation ::And:
            return left->Evaluate(date, event) && right->Evaluate(date, event);
        case LogicalOperation::Or:
            return left->Evaluate(date, event) || right->Evaluate(date, event);
        default: throw invalid_argument("expected comparison");
    }
}