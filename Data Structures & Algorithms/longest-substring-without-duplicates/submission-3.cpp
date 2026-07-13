class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> m;

        int max = 0;
        int from = 0;

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];

            if (const auto it = m.find(c); it != m.end()) {
                from = it->second + 1;
            }

            m[c] = i;
            max = std::max(max, i - from + 1);
        }

        return max;
    }
};
