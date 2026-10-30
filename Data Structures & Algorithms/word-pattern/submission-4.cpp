#include <ranges>

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::vector<std::string> mp1(26);

        std::stringstream ss;
        ss << s;

        int i = 0;
        for (std::string word; ss >> word; ++i) {
            const char c = pattern[i] - 'a';
            if (i == pattern.size()) return false;

            if (!mp1[c].empty()) {
                if (mp1[c] != word) return false;
            } else {
                for (const auto& w : mp1) {
                    if (w == word) return false;
                }

                mp1[c] = word;
            }
        }

        return i == pattern.size();
    }
};