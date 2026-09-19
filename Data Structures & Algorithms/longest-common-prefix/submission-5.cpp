class Solution {
public:
    // hor scanning
    // ver scanning
    // sorting
    string longestCommonPrefix(vector<string>& strs) {
        std::ranges::sort(strs);

        const std::string& first = strs.front();
        const std::string& last = strs.back();
        size_t i = 0;
        for (; i < std::min(
            first.size(), last.size()); ++i) {
            if (first[i] != last[i]) break;
        }

        return first.substr(0, i);
    }
};