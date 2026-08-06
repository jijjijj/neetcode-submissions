class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n1 = s1.size();
        const int n2 = s2.size();

        std::unordered_map<char, int> freq1;
        std::unordered_map<char, int> freq2;

        for (char c = 'a'; c <= 'z'; ++c) {
            freq1[c];
            freq2[c];
        }

        for (const char c : s1) ++freq1[c];


        for (int i = 0; i < n1; ++i) {
            ++freq2[s2[i]];
        }

        int matches = 0;
        for (const auto [c, cnt] : freq1) {
            if (freq2[c] == cnt) ++matches;
        }
        
        int l = 0;
        for (int i = n1; i < n2; ++i) {
            if (matches == 26) return true;
            const char c = s2[i];

            ++freq2[c];
            if (freq2[c] == freq1[c]) ++matches;
            else if (freq1[c] + 1 == freq2[c]) --matches;

            const char c2 = s2[l];
            --freq2[c2];
            if (freq2[c2] == freq1[c2]) ++matches;
            else if (freq1[c2] - 1 == freq2[c2]) --matches;

            ++l;
        }

        return false;
    }
};
