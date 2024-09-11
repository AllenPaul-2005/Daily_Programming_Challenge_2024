#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(const vector<int>& arr) {
    // Phase 1: Finding the intersection point of the two runners.
    int tortoise = arr[0];
    int hare = arr[0];
    
    do {
        tortoise = arr[tortoise];    // Move tortoise by one step
        hare = arr[arr[hare]];       // Move hare by two steps
    } while (tortoise != hare);      // Loop until they meet
    
    // Phase 2: Find the entrance to the cycle.
    tortoise = arr[0];               // Move tortoise to the start
    
    while (tortoise != hare) {
        tortoise = arr[tortoise];    // Move both one step
        hare = arr[hare];
    }
    
    return hare;  // Both pointers meet at the duplicate number
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};
    cout << "Duplicate number: " << findDuplicate(arr) << endl;
    return 0;
}
