#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int evaluatePostfix(const string &expression)
{
    stack<int> s;
    istringstream tokens(expression);
    string token;

    // Loop through each token in the expression
    while (tokens >> token)
    {
        // If token is a number, push it to the stack
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            s.push(stoi(token));
        }
        // Otherwise, it's an operator
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if (token == "+")
            {
                s.push(a + b);
            }
            else if (token == "-")
            {
                s.push(a - b);
            }
            else if (token == "*")
            {
                s.push(a * b);
            }
            else if (token == "/")
            {
                s.push(a / b); // Integer division truncating towards zero
            }
        }
    }

    return s.top(); // The result will be the only item left on the stack
}

int main()
{
    string expression = "2 1 + 3 *";
    cout << "Result: " << evaluatePostfix(expression) << endl;
    return 0;
}
