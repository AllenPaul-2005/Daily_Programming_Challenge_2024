#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int> &arr, int n)
{
    int total_sum = n * (n + 1) / 2;
    int arr_sum = 0;
    for (int num : arr)
    {
        arr_sum += num;
    }
    return total_sum - arr_sum;
}
int main()
{
    vector<int> arr = {3,1, 4, 5}; // Example input
    int n = 5;                      // n is the total count from 1 to n, which includes the missing number
    int res = findMissingNumber(arr, n);
    cout << "The missing number is: " << res << endl;
    return 0;
}
