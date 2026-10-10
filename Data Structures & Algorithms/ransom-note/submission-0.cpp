class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> freq;
        std::unordered_map<char, int> need;

        for (const char c : magazine) ++freq[c];
        for (const char c : ransomNote) ++need[c];

        for (const auto [c, f] : need) {
            if (freq[c] < f) return false;
        }

        return true;
    }
};