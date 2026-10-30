#include <ranges>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, std::string> mp1;
        std::unordered_set<std::string> mp2;

        std::stringstream ss;
        ss << s;

        int i = 0;
        for (std::string word; ss >> word; ++i) {
            const char c = pattern[i];
            if (i == pattern.size()) return false;

            if (mp1.contains(c)) {
                if (mp1[c] != word) return false;
            } else {
                if (mp2.contains(word)) return false;
                mp2.emplace(word);
                mp1[c] = word;
            }
        }

        return i == pattern.size();
    }
};