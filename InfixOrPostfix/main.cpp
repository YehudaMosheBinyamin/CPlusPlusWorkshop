#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>
#include <sstream>
/**
 * @brief Converts an infix expression to a postfix one: Eg. 1 + 2 will become 1 2 +
 * @param exp
 * @return postfix
*/
string infixToPostfix(string exp)
{
    string postfix;
    char ch;
    int expIndex = 0;
    stack<char>stack;
    do {
        ch = exp.at(expIndex);
        if (ch == '(')
        {
            stack.push('(');
        }
        else if (ch == ')')
        {
            while ((stack.empty() != true) && (stack.top() != '('))
            {
                postfix.push_back(' ');
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }
        else if (ch == '+')
        {
            while ((stack.empty() != true) && (stack.top() == '-') || (stack.top() == '*') || (stack.top() == '/'))
            {
                postfix.push_back(' ');
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(ch);
        }
        else if (ch == '-')
        {
            while ((stack.empty() != true) && (stack.top() == '*') || (stack.top() == '/'))
            {
                postfix.push_back(' ');
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(ch);
        }
        else if (ch == '*')
        {
            while ((stack.empty() != true) && (stack.top() == '/'))
            {
                postfix.push_back(' ');
                postfix.push_back(stack.top());
                stack.pop();
            }
            stack.push(ch);
        }
        else if (ch == '/')
        {
            stack.push(ch);
        }
        else if (isdigit(ch))
        {//If previous character wasn't a digit, add a space
            if ((expIndex > 0) && (!isdigit(exp.at(expIndex - 1))))
            {
                postfix.push_back(' ');
            }
            postfix.push_back(ch);
        }
        expIndex++;
    } while (expIndex < exp.length());

    while (stack.empty() == false)
    {
        postfix.push_back(' ');
        postfix.push_back(stack.top());
        stack.pop();
    }
    return postfix;
}
/**
 * @brief Calculates sum of a postfix expression
 * @param postfix
 * @return top of stack at end of calculation
*/
int calcPostfix(string postfix)
{
    stack<int>stack;
    int firstOperand;
    int secondOperand;
    int resultOperation;
    string numberOrOperator;
    int index = 0;
    while (index < postfix.length())
    {
        numberOrOperator.clear();
        if (postfix.at(index) == ' ')
        {
            index++;
            continue;
        }

        while (isdigit(postfix.at(index)))
        {
            numberOrOperator.push_back(postfix.at(index));
            index++;
        }
        if (postfix.at(index) == '+' || postfix.at(index) == '-' || postfix.at(index) == '/' || postfix.at(index) == '*')
        {
            numberOrOperator.push_back(postfix.at(index));
            index++;
        }

        if (all_of(numberOrOperator.begin(), numberOrOperator.end(), ::isdigit))
        {
            int number;
            stringstream numberStream(numberOrOperator);
            numberStream >> number;
            stack.push(number);
        }
        /*Otherwise it is an operator and so we will take out two top elements from the stack,
        perform operation with current operation and push back result into the stack*/
        else
        {

            int numTwo = stack.top();
            stack.pop();
            int numOne = stack.top();
            stack.pop();
            if (numberOrOperator.at(0) == '+')
            {
                resultOperation = numOne + numTwo;
            }
            if (numberOrOperator.at(0) == '-')
            {
                resultOperation = numOne - numTwo;
            }
            if (numberOrOperator.at(0) == '*')
            {
                resultOperation = numOne * numTwo;
            }
            if (numberOrOperator.at(0) == '/')
            {
                resultOperation = numOne / numTwo;
            }
            stack.push(resultOperation);
        }


    }
    return stack.top();
}
/**
 * @brief Receives an infix operation, prints its postfix, calculates it and prints it's result on the screen
 * @return
*/
int main()
{
    string exp;
    cout << "enter an infix expression as a string" << endl;
    cin >> exp;
    string postfix = infixToPostfix(exp);
    cout << postfix << endl;
    cout << calcPostfix(postfix) << endl;
    return 0;
}
/**
enter an infix expression as a string
(5 + 3)* ((20 / 10) + (8 - 6))
5 3 + 20 10 / 8 6 - +*
32
**/
