class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ref[26] = {};

        for (char c : s1) ++ref[c - 'a'];

        int freq[26] = {};
        int curr = 0;
        int l = 0;

        for (int i = 0; i < s2.size(); ++i) {
            const char c = s2[i] - 'a';
            ++freq[c];

            if (freq[c] <= ref[c] &&
                ++curr == s1.size()) {
                return true;
            }

            while (freq[c] > ref[c]) {
                const char cr = s2[l++] - 'a';

                if (ref[cr] > 0 && cr != c) {
                    --curr;
                }

                --freq[cr];
            }
        }

        return false;
    }
};
