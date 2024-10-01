#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i)
    {
        // Remove elements out of the current window
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        // Remove all elements smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        // Add the current element at the back of deque
        dq.push_back(i);

        // The front element is the largest element of the current window
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(arr, k);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
