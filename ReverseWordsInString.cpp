#include <iostream>
#include <stack>
using namespace std;
string reverseWordsUsingStack(string s)
{
    stack<string> wordStack;
    string word = "", result = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            word += s[i]; // Form the word
        }
        else if (word != "")
        {
            wordStack.push(word); // Push the word onto the stack
            word = "";            // Reset word
        }
    }
    // Don't forget the last word (if exists)
    if (word != "")
    {
        wordStack.push(word);
    }
    // Construct the result by popping words from the stack
    while (!wordStack.empty())
    {
        result += wordStack.top();
        wordStack.pop();
        if (!wordStack.empty())
        {
            result += " "; // Add a space between words
        }
    }

    return result;
}

int main()
{
    string s = "  the sky is   blue  ";
    cout << "Original String: '" << s << "'" << endl;
    string result = reverseWordsUsingStack(s);
    cout << "Reversed String: '" << result << "'" << endl;
    return 0;
}
