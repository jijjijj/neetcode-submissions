class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> mp1;
        std::unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); ++i) {
            const char a = s[i];
            const char b = t[i];

            if (mp1.contains(a) && mp1[a] != b) return false;
            if (mp2.contains(b) && mp2[b] != a) return false;

            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};