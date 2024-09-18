#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagramsOptimal(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagramMap;

    for (const std::string& str : strs) {
        std::string sortedStr = str;
        std::sort(sortedStr.begin(), sortedStr.end());
        anagramMap[sortedStr].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& pair : anagramMap) {
        result.push_back(pair.second);
    }
    
    return result;
}

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto anagrams = groupAnagramsOptimal(strs);
    
    for (const auto& group : anagrams) {
        std::cout << "[";
        for (const auto& word : group) {
            std::cout << word << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}
