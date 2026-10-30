#include <ranges>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, int> mp1;
        std::unordered_map<std::string, int> mp2;

        std::stringstream ss;
        ss << s;

        int i = 0;
        for (std::string word; ss >> word; ) {
            const char c = pattern[i];
            if (i == pattern.size() ||
                mp1[c] != mp2[word]) return false;

            mp1[c] = mp2[word] = ++i;
        }

        return i == pattern.size();
    }
};