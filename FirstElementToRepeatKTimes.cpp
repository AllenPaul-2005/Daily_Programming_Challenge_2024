#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int firstElementToRepeatKTimes(const vector<int> &arr, int k)
{
    unordered_map<int, int> freq_map;

    // Count the frequency of each element
    for (int num : arr)
    {
        freq_map[num]++;
    }

    // Find the first element that repeats exactly k times
    for (int num : arr)
    {
        if (freq_map[num] == k)
        {
            return num;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k = 2;

    int result = firstElementToRepeatKTimes(arr, k);
    cout << "Output: " << result << endl;

    return 0;
}
