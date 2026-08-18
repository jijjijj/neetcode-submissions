class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix;

        int min = std::numeric_limits<int>::max();
        for (const auto& str : strs) min = std::min(min, (int)str.size());

        for (int i = 0; i < min; ++i) {
            char c = strs[0][i];
            for (const auto& str : strs) {
                if (str[i] != c) return prefix;
            }
            prefix += c;
        }

        return prefix;
    }
};