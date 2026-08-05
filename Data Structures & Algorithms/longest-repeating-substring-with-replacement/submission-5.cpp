class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> freq;

        int max = 0;

        int l = 0;
        int maxf = 0;

        for (int i = 0; i < s.size(); ++i) {
            const char ch = s[i];
            
            if (++freq[ch] > maxf) {
                maxf = freq[ch];
            }

            if (i - l + 1 - maxf > k) --freq[s[l++]];            

            max = std::max(max, i - l + 1);
        }

        return max;
    }
};
