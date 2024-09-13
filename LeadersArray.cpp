#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findLeaders(vector<int> &arr)
{
    vector<int> leaders;
    int n = arr.size();
    int maxFromRight = arr[n - 1];
    leaders.push_back(maxFromRight);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= maxFromRight)
        {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}
int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findLeaders(arr);
    cout << "Leaders: ";
    for (int leader : leaders)
    {
        cout << leader << " ";
    }
    return 0;
}
