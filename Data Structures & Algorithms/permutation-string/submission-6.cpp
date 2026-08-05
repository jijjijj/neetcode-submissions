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
                const char c = s2[l++];
                if (std::abs(freq2[c] - 1 - freq1[c]) >
                    std::abs(freq2[c] - freq1[c])) {
                    --matches;
                } else {
                    ++matches;
                }

                --freq2[c];
            }

            const char c = s2[i];
            if (std::abs(freq2[c] + 1 - freq1[c]) >
                std::abs(freq2[c] - freq1[c])) {
                --matches;
            } else {
                ++matches;
            }
            ++freq2[c];

            if (matches == n1) return true;
        }

        return false;
    }
};
