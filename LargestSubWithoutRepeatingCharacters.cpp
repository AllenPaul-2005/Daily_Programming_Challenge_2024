#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> charIndex; // Map to store the most recent index of each character
    int maxLength = 0;                  // To keep track of the maximum length of substring found
    int left = 0;                       // Left pointer of the sliding window

    for (int right = 0; right < s.length(); right++)
    {
        char current = s[right];

        // If the character is already in the window, move the left pointer
        if (charIndex.find(current) != charIndex.end())
        {
            left = max(left, charIndex[current] + 1);
        }

        // Update the character's index in the map
        charIndex[current] = right;

        // Calculate the length of the current window and update maxLength
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main()
{
    string s = "abcabcbb"; // Example input
    cout << "Length of the longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}
