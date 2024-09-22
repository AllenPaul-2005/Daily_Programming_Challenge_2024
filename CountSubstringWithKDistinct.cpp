#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int countSubstrings(string s, int k)
{
    int n = s.length();
    unordered_map<char, int> freqMap;
    int start = 0, end = 0, count = 0, distinctCount = 0;
    while (end < n)
    {
        if (++freqMap[s[end]] == 1)
        {
            distinctCount++;
        }
        while (distinctCount > k)
        {
            if (--freqMap[s[start]] == 0)
            {
                distinctCount--;
            }
            start++;
        }
        if (distinctCount == k)
        {
            count += end - start + 1;
        }

        end++;
    }

    return count;
}

int main()
{
    string s = "pqvqs";
    int k = 2;
    cout << "Count of substrings with exactly " << k << " distinct characters: "
         << countSubstrings(s, k) << endl;
    return 0;
}
