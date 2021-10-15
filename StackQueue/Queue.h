#pragma once
/**
 * @brief Abstact class to reprtesent Queue data structure.
*/
class Queue
{
public:
    /**
     * @brief Clear queue
    */
    virtual void clear() = 0;
    /**
     * @brief Insert value to end of the queue
     * @param value
    */
    virtual void enqueue(int value) = 0;
    /**
     * @brief Take out and return first inserted value into the queue
     * @return
    */
    virtual int dequeue() = 0;
    /**
     * @brief Returns first inserted value into the queue
     * @return
    */
    virtual int front() = 0;
    /**
     * @brief Checks if queue is empty
     * @return
    */
    virtual bool isEmpty() const = 0;
};