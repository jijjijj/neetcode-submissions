class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> f(128, -1);

        int max = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            const int c = s[i];
            if (f[c] > -1) {
                cur = std::min(i - f[c], cur);
            } else {
                ++cur;
            }
            f[c] = i;

            max = std::max(cur, max);
        }

        return max;
    }
};
