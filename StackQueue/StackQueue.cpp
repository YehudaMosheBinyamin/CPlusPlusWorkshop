#include "StackQueue.h"

void StackQueue::clear()
{
    while (!data.empty())
    {
        data.pop();
    }
}

int StackQueue::dequeue()
{
    stack<int> helperStack;
    while (!data.empty())
    {
        helperStack.push(data.top());
        data.pop();
    }
    int result = helperStack.top();
    helperStack.pop();
    while (!helperStack.empty())
    {
        data.push(helperStack.top());
        helperStack.pop();
    }
    return result;
}

void StackQueue::enqueue(int value)
{
    data.push(value);
}

int StackQueue::front()
{
    stack<int> helperStack;
    while (!data.empty())
    {
        helperStack.push(data.top());
        data.pop();
    }
    int result = helperStack.top();
    while (!helperStack.empty())
    {
        data.push(helperStack.top());
        helperStack.pop();
    }
    return result;
}

bool StackQueue::isEmpty() const
{
    return data.empty();
}
