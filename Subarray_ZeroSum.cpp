#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> findZeroSumSubarrays(vector<int> &arr)
{
    vector<pair<int, int>> result;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                result.push_back({i, j});
            }
        }
    }
    return result;
}
int main()
{
    vector<int> arr = {1, 2, -3, 3, -1, 2};

    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    cout << "Subarrays with zero sum are: ";
    for (auto &p : subarrays)
    {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    return 0;
}
