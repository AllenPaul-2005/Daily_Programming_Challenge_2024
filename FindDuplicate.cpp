#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(const vector<int> &arr)
{
    int n = arr.size() - 1;           // Since array has n+1 elements
    int sum_of_n = (n * (n + 1)) / 2; // Sum of first n natural numbers

    int actual_sum = 0; // Sum of all elements in the array
    for (int num : arr)
    {
        actual_sum += num;
    }

    // The duplicate number is the difference between the actual sum and the expected sum
    return actual_sum - sum_of_n;
}

int main()
{
    vector<int> arr = {3, 1, 3, 4, 2};
    cout << "Duplicate number: " << findDuplicate(arr) << endl;
    return 0;
}
