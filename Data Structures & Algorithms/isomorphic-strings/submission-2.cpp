class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> mp1;
        std::unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); ++i) {
            const char a = s[i];
            const char b = t[i];

            if (mp1[a] != mp2[b]) return false;

            mp1[a] = i + 1;
            mp2[b] = i + 1;
        }

        return true;
    }
};