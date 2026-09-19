class Solution {
public:
    // hor scanning
    // ver scanning
    // +sorting
    string longestCommonPrefix(vector<string>& strs) {
        size_t i = 0;
        for (; i < strs.front().size(); ++i) {
            bool br = false;
            for (const auto& str : strs) {
                if (i == str.size() || str[i] != strs.front()[i]) {
                    br = true;
                    break;
                }
            }
            if (br) break;
        }

        return strs.front().substr(0, i);
    }
};