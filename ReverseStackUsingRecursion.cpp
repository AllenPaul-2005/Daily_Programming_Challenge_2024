#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int elem)
{
    if (st.empty())
    {
        st.push(elem);
    }
    else
    {
        int topElem = st.top();
        st.pop();
        insertAtBottom(st, elem);
        st.push(topElem);
    }
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st)
{
    if (!st.empty())
    {
        int topElem = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, topElem);
    }
}

int main()
{
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
