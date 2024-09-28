#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element into the sorted stack
void insertSorted(stack<int> &st, int element) {
    if (st.empty() || element > st.top()) {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(topElement);
}

// Function to sort the stack using recursion
void sortStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }

    int topElement = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, topElement);
}

// Function to print the stack elements from bottom to top using recursion
void printStackRecursively(stack<int> &st) {
    if (st.empty()) {
        return;
    }

    int topElement = st.top();
    st.pop();
    printStackRecursively(st);
    cout << topElement << " ";
    st.push(topElement);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    cout << "Sorted Stack: ";
    printStackRecursively(st);
    cout << endl;

    return 0;
}
