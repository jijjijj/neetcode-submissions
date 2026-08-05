class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> freq1;

        for (const char c : s1) ++freq1[c];

        std::unordered_map<char, int> freq2;

        const int n1 = s1.size();
        const int n2 = s2.size();
        int matches = 0;
        int l = 0;
        for (int i = 0; i < n2; ++i) {
            if (i - l + 1 > n1) {
                if (std::abs(freq2[s2[l]] - 1 - freq1[s2[l]]) >
                    std::abs(freq2[s2[l]] - freq1[s2[l]])) {
                    --matches;
                } else {
                    ++matches;
                }

                --freq2[s2[l++]];
            }
            if (std::abs(freq2[s2[i]] + 1 - freq1[s2[i]]) >
                std::abs(freq2[s2[i]] - freq1[s2[i]])) {
                --matches;
            } else {
                ++matches;
            }
            ++freq2[s2[i]];

            if (matches == n1) return true;
        }

        return false;
    }
};
