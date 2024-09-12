#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int i = m - 1; // Pointer to the last element in arr1
    int j = 0;     // Pointer to the first element in arr2

    // Compare the elements and swap if needed
    while (i >= 0 && j < n)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
        }
        i--;
        j++;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7}; // Initial sorted array arr1
    vector<int> arr2 = {2, 4, 6, 8}; // Initial sorted array arr2
    int m = arr1.size();
    int n = arr2.size();
    mergeSortedArrays(arr1, arr2, m, n);
    cout << "arr1 = ";
    for (int i = 0; i < m; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "arr2 = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
