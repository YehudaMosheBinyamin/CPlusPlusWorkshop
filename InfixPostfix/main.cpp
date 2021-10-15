#include <iostream>
using namespace std;
#include <stack>
string infixToPostfix(string expr)
{
	string postfix = "";
	stack<char> stack;
	char ch;
	for (int i = 1; i < expr.length(); ++i)
	{   
		ch = expr.at(i);
		if (ch == '(')
		{
			stack.push(ch);
		}
		if (ch == ')')
		{
			while (stack.top() != '(')
			{
				postfix += " "+stack.top();
				stack.pop();
			}
			stack.pop();
		}

		if (isdigit(ch))
		{
			postfix += " " + ch;
		}
		
	}

}
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
