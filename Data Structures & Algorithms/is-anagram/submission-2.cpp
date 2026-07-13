class Solution {
public:
    bool isAnagram(string s, string t) {
        int sf[26]{};
        int tf[26]{};

        for (char c : s) ++sf[c - 'a'];
        for (char c : t) ++tf[c - 'a'];

        for (int i = 0; i < 26; ++i) {
            if (sf[i] != tf[i]) return false;
        }

        return true;
    }
};
