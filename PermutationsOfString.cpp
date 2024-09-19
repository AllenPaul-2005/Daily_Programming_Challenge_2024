#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void permute(string s, int l, int r, vector<string> &result)
{
    if (l == r)
    {
        result.push_back(s);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            if (i != l && s[i] == s[l])
                continue;    
            swap(s[l], s[i]); 
            permute(s, l + 1, r, result);
            swap(s[l], s[i]); 
        }
    }
}

vector<string> generatePermutations(string s)
{
    sort(s.begin(), s.end()); 
    vector<string> result;
    permute(s, 0, s.size() - 1, result);
    sort(result.begin(), result.end());                               
    result.erase(unique(result.begin(), result.end()), result.end()); 
    return result;
}

int main()
{
    string s = "abc"; // Input string
    vector<string> permutations = generatePermutations(s);

    cout << "Permutations of the string \"" << s << "\":" << endl;
    for (const string &perm : permutations)
    {
        cout << perm << endl;
    }

    return 0;
}
