class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, int> mp1;
        std::unordered_map<char, int> mp2;

        for (int i = 0; i < s.size(); ++i) {
            const char a = s[i];
            const char b = t[i];

            if (!mp1.contains(a)) mp1[a] = mp1.size();
            if (!mp2.contains(b)) mp2[b] = mp2.size();

            if (mp1[a] != mp2[b]) return false;
        }

        return true;
    }
};