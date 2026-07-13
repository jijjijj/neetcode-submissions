class Solution {
public:
    int characterReplacement(string s, int k) {
        int max = 0;

        int freq[26] = {};
        int l = 0;
        int maxf = 0;

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i] - 'A';

            ++freq[c];

            maxf = std::max(maxf, freq[c]);
            while ((i - l + 1) - maxf > k) {
                --freq[s[l++] - 'A'];
            }

            max = std::max(max, i - l + 1);
        }

        return max;
    }
};
