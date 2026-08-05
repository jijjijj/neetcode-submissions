class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> f(128, -1);

        int max = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            const int c = s[i];
            while (f[c] > -1) f[s[start++]] = -1;
            f[c] = i;

            max = std::max(i - start + 1, max);
        }

        return max;
    }
};
