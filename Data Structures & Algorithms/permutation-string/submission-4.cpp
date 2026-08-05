class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> freq1;

        for (const char c : s1) ++freq1[c];

        std::unordered_map<char, int> freq2;

        const int n1 = s1.size();
        const int n2 = s2.size();
        int l = 0;
        for (int i = 0; i < n2; ++i) {
            if (i - l + 1 > n1) {
                --freq2[s2[l++]];
            }
            ++freq2[s2[i]];

            bool match = true;

            for (const auto [c, cnt] : freq1) {
                if (freq2[c] != cnt) {
                    match = false;
                    break;
                }
            }

            if (match) return true;
        }

        return false;
    }
};
