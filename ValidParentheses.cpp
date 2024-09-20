#include <iostream>
#include <stack>
#include <unordered_map>

bool isValidBetter(std::string s)
{
    std::stack<char> st;
    std::unordered_map<char, char> matching = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s)
    {
        if (matching.count(c))
        { // It's a closing bracket
            if (st.empty() || st.top() != matching[c])
            {
                return false; // No matching opening bracket
            }
            st.pop(); // Matching pair found
        }
        else
        {
            st.push(c); // Push opening bracket
        }
    }
    return st.empty(); // True if all brackets are matched
}
int main()
{
    std::string s = "[{()}]";
    std::cout << (isValidBetter(s) ? "true" : "false") << std::endl;
    return 0;
}
