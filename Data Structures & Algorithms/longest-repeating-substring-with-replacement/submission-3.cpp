class Solution {
public:
    int characterReplacement(string s, int k) {
        int max = 0;

        for (char f = 0; f < 26; ++f) {
            int w = 0;
            int l = 0;
            for (int i = 0; i < s.size(); ++i) {
                const char c = s[i] - 'A';

                w += (c != f);

                while (w > k) {
                    w -= ((s[l++] - 'A') != f);
                }

                max = std::max(max, i - l + 1);
            }
        }

        return max;
    }
};
