class Solution {
public:
    // hor scanning
    // ver scanning
    // +sorting
    string longestCommonPrefix(vector<string>& strs) {
        size_t prefix = strs.front().size();

        for (size_t i = 1; i < strs.size(); ++i) {
            size_t j = 0;
            for (; j < std::min(prefix, strs[i].size()); ++j) {
                if (strs.front()[j] != strs[i][j]) break;
            }

            prefix = j;
        }

        return strs.front().substr(0, prefix);
    }
};