#pragma once
using namespace std;
#include <stack>
#include "Queue.h"
/**
 * @brief Class to represent a stack queue-a queue implemented with a stack, and using a helper stack for front
 *dequeue and enqueue operations
*/
class StackQueue : public Queue
{
protected:
    stack<int> data;
public:
    /**
     * @brief Clears the stack
    */
    void clear() override;
    /**
     * @brief Takes out and returns out element inserted the first into the StackQueue
     * @return
    */
    int dequeue() override;
    /**
     * @brief Inserts a value to the end of the StackQueue
     * @param value
    */
    void enqueue(int value) override;
    /**
     * @brief Returns out element inserted the first into the StackQueue
     * @return
    */
    int front() override;
    /**
     * @brief Checks if StackQueue is empty
     * @return
    */
    bool isEmpty() const override;
};