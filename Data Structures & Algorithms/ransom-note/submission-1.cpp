class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> freq;

        for (const char c : magazine) ++freq[c];

        for (const char c : ransomNote) {
            if (--freq[c] < 0) return false;
        }

        return true;
    }
};