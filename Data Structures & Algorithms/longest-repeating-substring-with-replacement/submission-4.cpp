class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_set<char> chars;

        for (const char c : s) chars.emplace(c);

        int max = 0;

        for (const char c : chars) {
            int l = 0;
            int cur = 0; // count of wrong characters
            for (int i = 0; i < s.size(); ++i) {
                const char ch = s[i];
                cur += (ch != c);

                while (cur > k) cur -= (s[l++] != c);

                max = std::max(max, i - l + 1);
            }
        }

        return max;
    }
};
