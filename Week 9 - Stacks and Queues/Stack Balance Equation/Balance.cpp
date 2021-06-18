#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

bool inline balanced(string exp)
{
    stack<char> parens;

    for (char ch : exp)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            parens.push(ch);
        }

        if (ch == ')' || ch == ']' || ch == '}')
        {
            //pop
            if (parens.empty())
            {
                return false;
                //stack is prematurely empty
            } //end of stack empty check

            char top = parens.top();
            parens.pop();

            if ((top == '(' && ch != ')') ||
                (top == '[' && ch != ']') ||
                (top == '{' && ch != '}'))
            {
                return false;
            } //end of second if
        }     //end of first if

    } //end of for loop
    //stack should be empty at this point
    return parens.empty();
}

int main()
{
    string exp = "4 * ( 5 / 10) * (10 + 2)";
    string exp2 = "[(3 + x) - (7 + x)]";
    string exp3 = "[(3 + {x + 15}) - ({7 - 32} + x)]";

    if (balanced(exp3))
    {
        cout << exp3 << " is balanced :) \n";
    }
    else
    {
        cout << exp3 << " is NOT balanced :( \n";
    }
}
